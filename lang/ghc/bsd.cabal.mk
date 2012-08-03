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

HSPREFIX=	hs-
PKGNAMEPREFIX?=	${HSPREFIX}

.if !defined(METAPORT)
MASTER_SITES?=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
.else
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty
NO_FETCH=	yes
NO_BUILD=	yes
.endif # !METAPORT

DIST_SUBDIR?=	cabal

FILE_LICENSE?=	LICENSE

.if !defined(STANDALONE)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
BUILD_DEPENDS+=	ghc>=${GHC_VERSION}:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc>=${GHC_VERSION}:${PORTSDIR}/lang/ghc
.elif defined(STANDALONE)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
BUILD_DEPENDS+=	ghc>=${GHC_VERSION}:${PORTSDIR}/lang/ghc
.endif

GHC_VERSION?=	7.4.1
GHC_VERSION_N=	${GHC_VERSION:S/./0/g}

GHC_CMD?=	${LOCALBASE}/bin/ghc
CABAL_SETUP?=	Setup.lhs
SETUP_CMD?=	./setup

ALEX_CMD?=	${LOCALBASE}/bin/alex
HAPPY_CMD?=	${LOCALBASE}/bin/happy
HADDOCK_CMD?=	${LOCALBASE}/bin/haddock
C2HS_CMD?=	${LOCALBASE}/bin/c2hs

CABAL_DIRS+=	${DATADIR} ${EXAMPLESDIR} ${CABAL_LIBDIR}/${CABAL_LIBSUBDIR}

GHC_HADDOCK_CMD=${LOCALBASE}/bin/haddock-ghc-${GHC_VERSION}

CABAL_DOCSDIR=		${PREFIX}/share/doc/ghc-${GHC_VERSION}/cabal
CABAL_DOCSDIR_REL=	${CABAL_DOCSDIR:S,^${PREFIX}/,,}

DATADIR=	${PREFIX}/share/ghc-${GHC_VERSION}/cabal/${DISTNAME}
DOCSDIR=	${CABAL_DOCSDIR}/${DISTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ghc-${GHC_VERSION}/cabal/${DISTNAME}

GHC_LIB_DOCSDIR_REL=	share/doc/ghc-${GHC_VERSION}/html/libraries

CABAL_LIBDIR=		${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
CABAL_LIBSUBDIR=	${DISTNAME}
CABAL_LIBDIR_REL=	${CABAL_LIBDIR:S,^${PREFIX}/,,}

CONFIGURE_ARGS+=	--libdir=${CABAL_LIBDIR} --libsubdir=${CABAL_LIBSUBDIR}

PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION} \
		LIBDIR_REL=${CABAL_LIBDIR_REL}/${CABAL_LIBSUBDIR}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

INSTALL_PORTDATA?=
INSTALL_PORTEXAMPLES?=

HSCOLOUR_DESC?=	Colorize generated documentation by HsColour
DYNAMIC_DESC?=	Add support for dynamic linking
PROFILE_DESC?=	Add support for profiling

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/lib/ghc-${GHC_VERSION}/ghc-${GHC_VERSION}/GHC.dyn_hi)
OPTIONS_DEFINE+=	DYNAMIC
.endif

.if exists(${LOCALBASE}/lib/ghc-${GHC_VERSION}/ghc-${GHC_VERSION}/GHC.p_hi)
OPTIONS_DEFINE+=	PROFILE
.endif

.if exists(${HADDOCK_CMD}) && exists(${LOCALBASE}/lib/ghc-${GHC_VERSION}/html)
OPTIONS_DEFINE+=	DOCS HSCOLOUR
OPTIONS_DEFAULT+=	DOCS
.endif

.if defined(USE_ALEX)
BUILD_DEPENDS+=	${ALEX_CMD}:${PORTSDIR}/devel/hs-alex
CONFIGURE_ARGS+=	 --with-alex=${ALEX_CMD}
.endif

.if defined(USE_HAPPY)
BUILD_DEPENDS+=	${HAPPY_CMD}:${PORTSDIR}/devel/hs-happy
CONFIGURE_ARGS+=	 --with-happy=${HAPPY_CMD}
.endif

.if defined(USE_C2HS)
BUILD_DEPENDS+=	${C2HS_CMD}:${PORTSDIR}/devel/hs-c2hs
CONFIGURE_ARGS+=	--with-c2hs=${C2HS_CMD}
.endif

.if defined(EXECUTABLE)
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
USE_ICONV=	yes
.endif

.if defined(EXECUTABLE) && ${PORT_OPTIONS:MDOCS}
HADDOCK_EXE?=	--executables
.endif

.if defined(USE_CABAL)
.include "bsd.hackage.mk"

.for cabal_package in ${USE_CABAL}
__u_h_r_package=	${cabal_package:C/[<=>].*$//g}
__u_h_r_port=		${${__u_h_r_package}_port}
__u_h_r_name=		${__u_h_r_port:C/.*\///g}

.if empty(__u_h_r_port)
IGNORE?=	dependency fails: ${cabal_package:C/[<=>].*$//g} is not known as a port
.endif

.if ${__u_h_r_package} == ${cabal_package}
__u_h_r_version:=	>=0
.else
__u_h_r_version:=	${cabal_package:C/^[^<=>]*//g}
.endif

dependencies:=	${dependencies} \
${HSPREFIX}${__u_h_r_package}${__u_h_r_version}:${PORTSDIR}/${__u_h_r_port}
.endfor

BUILD_DEPENDS+=	${dependencies}

.if !defined(STANDALONE)
RUN_DEPENDS+=	${dependencies}
.endif

.endif

.if defined(USE_GHC_NATIVE)
USE_PERL5_BUILD=	5.8+
.endif

.if ${PORT_OPTIONS:MDOCS}
.if !defined(XMLDOCS)

HADDOCK_OPTS=	${HADDOCK_EXE}

.if ${PORT_OPTIONS:MHSCOLOUR}
BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.20.2
HSCOLOUR_DATADIR=	${LOCALBASE}/share/ghc-${GHC_VERSION}/cabal/hscolour-${HSCOLOUR_VERSION}
HADDOCK_OPTS+=		--hyperlink-source --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif # HSCOLOUR

.endif

.if defined(XMLDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt

USE_GMAKE=	yes

.endif # !XMLDOCS

.if !defined(METAPORT)
PORTDOCS=	*
.endif # !METAPORT

.endif # DOCS

__handle_datadir__=	--datadir='${DATADIR}' --datasubdir='' --docdir='${DOCSDIR}'

.if !defined(XMLDOCS) && ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--haddock-options=-w --with-haddock=${HADDOCK_CMD}
.endif

.if ${PORT_OPTIONS:MDYNAMIC}
CONFIGURE_ARGS+=	--enable-shared
.else
CONFIGURE_ARGS+=	--disable-shared
.endif

.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--enable-executable-profiling --enable-library-profiling
.else
CONFIGURE_ARGS+=	--disable-executable-profiling --disable-library-profiling
.endif

.SILENT:

post-patch::
.if defined(XMLDOCS) && defined(USE_AUTOTOOLS)
	@${REINPLACE_CMD} -e 's|/usr/local/share/xsl/docbook|${LOCALBASE}/share/xsl/docbook|' \
		${WRKSRC}/doc/configure.ac
.endif

# Purge Haskell 98 (required for GHC 7.2 or later)
.if defined(HASKELL98)
	@${REINPLACE_CMD} -E 's|haskell98[,]?||' \
		${WRKSRC}/${PORTNAME}.cabal

	@${REINPLACE_CMD} 's|import List|import Data.List| ; \
		s|import Char|import Data.Char| ; \
		s|import Ratio|import Data.Ratio| ; \
		s|import Monad|import Control.Monad| ; \
		s|import IO|import System.IO.Error| ; \
		s|import Directory|import System.Directory| ; \
		s|import Maybe|import Data.Maybe| ; \
		s|import Array|import Data.Array|' \
		`${FIND} ${WRKSRC} -name '*.hs'`
.endif

.if !target(do-configure)
do-configure:
.if !defined(METAPORT)
	cd ${WRKSRC} && ${GHC_CMD} --make ${CABAL_SETUP} -o setup -package Cabal
	cd ${WRKSRC} && ${SETENV} CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" \
			${SETUP_CMD} configure --ghc --prefix=${PREFIX} --extra-include-dirs="${LOCALBASE}/include" --extra-lib-dirs="${LOCALBASE}/lib" ${__handle_datadir__} ${CONFIGURE_ARGS}

.if ${PORT_OPTIONS:MDOCS}
.if defined(XMLDOCS) && defined(USE_AUTOTOOLS)
	cd ${WRKSRC}/doc && ${AUTOCONF} && ./configure --prefix=${PREFIX}
.endif
.endif # DOCS
.else
	${DO_NADA}
.endif # !METAPORT
.endif # target(do-configure)

.if !target(do-build)
do-build:
.if !defined(METAPORT)
	cd ${WRKSRC} && ${SETUP_CMD} build
.if !defined(STANDALONE)
	cd ${WRKSRC} && ${SETUP_CMD} register --gen-script
.endif

.if ${PORT_OPTIONS:MDOCS}
.if !defined(XMLDOCS) && !defined(STANDALONE) && ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${SETUP_CMD} haddock ${HADDOCK_OPTS}
.endif # STANDALONE
.if defined(XMLDOCS)
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif # XMLDOCS
.endif # DOCS
.else
	${DO_NADA}
.endif # !METAPORT
.endif # target(do-build)

.if !target(do-install)
do-install:
.if !defined(METAPORT)
	cd ${WRKSRC} && ${SETUP_CMD} install

.if !defined(STANDALONE)
	cd ${WRKSRC} && ${INSTALL_SCRIPT} register.sh ${CABAL_LIBDIR}/${CABAL_LIBSUBDIR}/register.sh
.endif

.if !empty(INSTALL_PORTDATA)
	@${MKDIR} ${DATADIR}
	${INSTALL_PORTDATA}
.endif

.if !empty(INSTALL_PORTEXAMPLES) && ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PORTEXAMPLES}
.endif

.if defined(MAN1SRC)
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${MAN1SRC}/${man} ${PREFIX}/man/man1
.endfor
.endif # MAN1SRC

.if ${PORT_OPTIONS:MDOCS}
.if !empty(XMLDOCS)
.for xmldoc in ${XMLDOCS}
	@(cd ${WRKSRC}/${xmldoc:C/:.*$//g} && ${COPYTREE_SHARE} \* ${DOCSDIR}/${xmldoc:C/^.*://g})
.endfor
.endif # XMLDOCS
.endif
.else
	${DO_NADA}
.endif # !METAPORT
.endif # target(do-install)

.if !target(post-install-script)
post-install-script:
	@for dir in ${CABAL_DIRS}; do if [ -d $${dir} ]; then ${FIND} -ds $${dir} \
		-type f -print | ${SED} -E -e 's,^${PREFIX}/?,,' >> ${TMPPLIST}; fi ; \
		if [ -d $${dir} ]; then ${FIND} -ds $${dir} \
		-type d -print | ${SED} -E -e 's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}; fi ; done
.if defined(EXECUTABLE)
.for exe in ${EXECUTABLE}
	@${ECHO_CMD} 'bin/${exe}' >>${TMPPLIST}
.endfor
.endif

.endif # target(post-install-script)

add-plist-post: add-plist-cabal
add-plist-cabal:
.if !defined(METAPORT)
	@if [ -f ${CABAL_LIBDIR}/${CABAL_LIBSUBDIR}/register.sh ]; then \
		(${ECHO_CMD} '@exec ${SH} %D/${CABAL_LIBDIR_REL}/${CABAL_LIBSUBDIR}/register.sh'; \
		 ${ECHO_CMD} '@unexec %D/bin/ghc-pkg unregister --force ${PORTNAME}-${PORTVERSION}') >> ${TMPPLIST}; fi
.if empty(PORT_OPTIONS:MDOCS)
	@if [ -f ${DOCSDIR}/${FILE_LICENSE} ]; then \
		(${ECHO_CMD} '${DOCSDIR_REL}/${FILE_LICENSE}'; \
		 ${ECHO_CMD} '@unexec ${RMDIR} "%D/${DOCSDIR_REL}" 2>/dev/null || true') >>${TMPPLIST}; fi
.else
	@(${ECHO_CMD} '@exec if [ -f %D/${GHC_LIB_DOCSDIR_REL}/gen_contents_index ]; then ${LN} -s ${DOCSDIR}/html %D/${GHC_LIB_DOCSDIR_REL}/${DISTNAME} && \
		cd %D/${GHC_LIB_DOCSDIR_REL} && ${RM} -f doc-index*.html && ./gen_contents_index; fi' ; \
	  ${ECHO_CMD} '@unexec ${RM} -f %D/${GHC_LIB_DOCSDIR_REL}/${DISTNAME}' ; \
	  ${ECHO_CMD} '@unexec if [ -f %D/${GHC_LIB_DOCSDIR_REL}/gen_contents_index ]; then cd %D/${GHC_LIB_DOCSDIR_REL} && ${RM} -f doc-index*.html && ./gen_contents_index; fi') >>${TMPPLIST};
.endif
.else
	${DO_NADA}
.endif # !METAPORT

post-install::
.if !defined(METAPORT)
.if ${PORT_OPTIONS:MDOCS}
	@if [ -f ${PREFIX}/${GHC_LIB_DOCSDIR_REL}/gen_contents_index ]; then \
		${LN} -s ${DOCSDIR}/html ${PREFIX}/${GHC_LIB_DOCSDIR_REL}/${DISTNAME} && \
		cd ${PREFIX}/${GHC_LIB_DOCSDIR_REL} && \
		${RM} -f doc-index*.html && ./gen_contents_index; \
	fi
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
.else
	${DO_NADA}
.endif # !METAPORT
