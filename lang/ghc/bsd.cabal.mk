#
# $FreeBSD$
#
# bsd.cabal.mk -- Support for ports based on Haskell Cabal.
#
# Created by: Gabor Pali <pgj@FreeBSD.org>,
# Based on works of Giuseppe Pilichi and Ashish Shukla.
#
# Maintained by: haskell@FreeBSD.org
#

MASTER_SITES?=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX?=	hs-

.if !defined(DOCUMENTATION) && \
    (${PORTNAME} == haddock || ${PORTNAME} == ghc-paths || ${PORTNAME} == hscolour)
NOPORTDOCS=	yes
.endif

.if defined(NOPORTDOCS) && defined(DOCUMENTATION)
IGNORE+=	is a documentation-only port, do not install if no documentation needed
.endif

.if !defined(SLAVE) && !defined(DOCUMENTATION)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.endif

.if defined(SLAVE)
NO_PKG_REGISTER=
.endif

GHC_VERSION?=	6.10.4

GHC_CMD?=	${LOCALBASE}/bin/ghc
CABAL_SETUP?=	Setup.lhs
SETUP_CMD?=	./setup

DATADIR=	${PREFIX}/share/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${DISTNAME}

LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION} \
		LIBDIR_REL=${LIBDIR_REL}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

INSTALL_PORTDATA?=
INSTALL_PORTEXAMPLES?=

.if defined(USE_ALEX)
BUILD_DEPENDS+=	${LOCALBASE}/bin/alex:${PORTSDIR}/devel/hs-alex
.endif

.if defined(USE_HAPPY)
BUILD_DEPENDS+=	${LOCALBASE}/bin/happy:${PORTSDIR}/devel/hs-happy
.endif

.if defined(EXECUTABLE)
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
.endif

.if defined(EXECUTABLE) || defined(DOCUMENTATION)
HADDOCK_EXE?=	--executables
.endif

.if defined(DOCUMENTATION)

.if defined(PORTREVISION) && ${PORTREVISION} != 0
_SUF1=	_${PORTREVISION}
.endif

.if defined(PORTEPOCH) && ${PORTEPOCH} != 0
_SUF2=	,${PORTEPOCH}
.endif

PKGVERSION=	${PORTVERSION:C/[-_,]/./g}${_SUF1}${_SUF2}

PKGNAMESUFFIX=	-docs
USE_HACKAGE+=	${PORTNAME}==${PKGVERSION}
.endif

.if !defined(SLAVE)
.if defined(USE_HACKAGE)
.include "bsd.hackage.mk"

.for hackage in ${USE_HACKAGE}
__u_h_r_package=	${hackage:C/[<=>].*$//g}
__u_h_r_port=		${${__u_h_r_package}_port}
__u_h_r_name=		${__u_h_r_port:C/.*\///g}

.if ${__u_h_r_package} == ${hackage}
__u_h_r_version:=	>=0
.else
__u_h_r_version:=	${hackage:C/^[^<=>]*//g}
.endif

dependencies:=	${dependencies} \
${__u_h_r_name}${__u_h_r_version}:${PORTSDIR}/${__u_h_r_port}
.endfor

.if !defined(DOCUMENTATION)
BUILD_DEPENDS+=	${dependencies}
.endif
.if !defined(STANDALONE)
RUN_DEPENDS+=	${dependencies}
.endif

.endif
.endif

.if defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS=""
.else
PLIST_SUB+=	NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)
.if !defined(XMLDOCS) || defined(DOCUMENTATION)
PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if !empty(PORT_HADDOCK:M?0)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif

BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${LOCALBASE}/share/hscolour-${HSCOLOUR_VERSION}

.endif

.if defined(XMLDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt

USE_GMAKE=	yes

.endif # !XMLDOCS

.if !defined(DOCUMENTATION)
PORTDOCS=	*
.else
PORTDOCS=	html

.if !empty(XMLDOCS)
.for xmldoc in ${XMLDOCS}
PORTDOCS+=	${xmldoc:C/^.*://g}
.endfor
.endif

.endif # !DOCUMENTATION

.endif # !NOPORTDOCS

.if defined(PORTDATA) && defined(NOPORTDATA)
__handle_datadir__=	--datadir='' --datasubdir='' --docdir='${DOCSDIR}'
.else
__handle_datadir__=
.endif

MAN1SRC?=	man/man1


.if (!defined(XMLDOCS) || defined(DOCUMENTATION)) && !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--haddock-options=-w
.endif

.SILENT:

post-patch:
.if defined(XMLDOCS) && defined(USE_AUTOTOOLS)
	@${REINPLACE_CMD} -e 's|/usr/local/share/xsl/docbook|${LOCALBASE}/share/xsl/docbook|' \
		${WRKSRC}/doc/configure.ac
.endif

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make ${CABAL_SETUP} -o setup -package Cabal
	cd ${WRKSRC} && ${SETENV} CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" \
				${SETUP_CMD} configure --ghc --prefix=${PREFIX} --extra-include-dirs="${LOCALBASE}/include" --extra-lib-dirs="${LOCALBASE}/lib" ${__handle_datadir__} ${CONFIGURE_ARGS}

.if !defined(NOPORTDOCS)
.if defined(XMLDOCS) && defined(USE_AUTOTOOLS)
	cd ${WRKSRC}/doc && ${AUTOCONF} && ./configure --prefix=${PREFIX}
.endif
.endif # !NOPORTDOCS

do-build:
.if !defined(DOCUMENTATION)
	cd ${WRKSRC} && ${SETUP_CMD} build
.if !defined(SLAVE) && !defined(STANDALONE)
	cd ${WRKSRC} && ${SETUP_CMD} register --gen-script
.endif
.endif # !DOCUMENTATION

.if !defined(NOPORTDOCS)
.if (!defined(XMLDOCS) && !defined(STANDALONE)) || defined(DOCUMENTATION)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source ${HADDOCK_EXE} \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif # STANDALONE
.if defined(XMLDOCS)
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif # XMLDOCS
.endif # !NOPORTDOCS

do-install:
.if !defined(DOCUMENTATION)
	cd ${WRKSRC} && ${SETUP_CMD} install

.if !defined(SLAVE) && !defined(STANDALONE)
	cd ${WRKSRC} && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${LIBDIR_REL}/register.sh
.endif

.if !empty(INSTALL_PORTDATA) && !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	${INSTALL_PORTDATA}
.endif

.if !empty(INSTALL_PORTEXAMPLES) && !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PORTEXAMPLES}
.endif

.if defined(MAN1)
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${MAN1SRC}/${man} ${PREFIX}/man/man1
.endfor
.endif # MAN1

.else

	@(cd ${WRKSRC}/dist/doc/html/${PORTNAME} && ${COPYTREE_SHARE} \* ${DOCSDIR}/html)

.endif # !DOCUMENTATION

.if !defined(NOPORTDOCS)
.if !empty(XMLDOCS)
.for xmldoc in ${XMLDOCS}
	@(cd ${WRKSRC}/${xmldoc:C/:.*$//g} && ${COPYTREE_SHARE} \* ${DOCSDIR}/${xmldoc:C/^.*://g})
.endfor
.endif # XMLDOCS
.endif

post-install:
.if !defined(SLAVE) && !defined(STANDALONE) && !defined(DOCUMENTATION)
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.endif

.if defined(EXECUTABLE)
.for exe in ${EXECUTABLE}
	@${STRIP_CMD} ${PREFIX}/bin/${exe}
	@${CHMOD} ${BINMODE} ${PREFIX}/bin/${exe}
.endfor
.endif # EXECUTABLE

.if defined(SHOW_PKGMSG)
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "================================================================="
	@${CAT}      "${PKGMESSAGE}"
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG}
.endif # SHOW_PKGMSG
