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

.if !defined(METAPORT)
MASTER_SITES?=	http://hackage.haskell.org/package/${PORTNAME}-${PORTVERSION}/
DIST_SUBDIR?=	cabal
.else
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty
NO_FETCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes
.endif # !METAPORT

MAKE_ENV+=	LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 DESTDIR=${STAGEDIR}

SETUP_CMD?=	./setup

ALEX_CMD?=	${LOCALBASE}/bin/alex
HAPPY_CMD?=	${LOCALBASE}/bin/happy
C2HS_CMD?=	${LOCALBASE}/bin/c2hs

CABAL_DIRS+=	${DATADIR} ${EXAMPLESDIR} ${CABAL_LIBDIR}/${CABAL_LIBSUBDIR} \
		${DOCSDIR}

GHC_HADDOCK_CMD=${LOCALBASE}/bin/haddock-ghc-${GHC_VERSION}

CABAL_DOCSDIR=		${PREFIX}/share/doc/cabal/ghc-${GHC_VERSION}
CABAL_DOCSDIR_REL=	${CABAL_DOCSDIR:S,^${PREFIX}/,,}

DATADIR=	${PREFIX}/share/cabal/ghc-${GHC_VERSION}/${DISTNAME}
DOCSDIR=	${CABAL_DOCSDIR}/${DISTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/cabal/ghc-${GHC_VERSION}/${DISTNAME}

GHC_LIB_DOCSDIR_REL=	share/doc/ghc-${GHC_VERSION}/html/libraries

CABAL_LIBDIR=		${PREFIX}/lib/cabal/ghc-${GHC_VERSION}
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

LOCALBASE?=	/usr/local

.if !defined(CABALOPTIONSMKINCLUDED)
.include "bsd.cabal.options.mk"
.endif

.if !defined(STANDALONE) || ${PORT_OPTIONS:MDYNAMIC}
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
BUILD_DEPENDS+=	ghc>=${GHC_VERSION}:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc>=${GHC_VERSION}:${PORTSDIR}/lang/ghc
.else
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
BUILD_DEPENDS+=	ghc>=${GHC_VERSION}:${PORTSDIR}/lang/ghc
.endif

USE_BINUTILS=	yes
USE_GCC=	yes

CONFIGURE_ARGS+=	--with-gcc=${CC} --with-ld=${LD} --with-ar=${AR} \
			--with-ranlib=${RANLIB}

.if ${PORT_OPTIONS:MLLVM}
CONFIGURE_ARGS+=	--ghc-option=-fllvm \
			--ghc-option=-pgmlo --ghc-option=${LOCALBASE}/bin/opt32 \
			--ghc-option=-pgmlc --ghc-option=${LOCALBASE}/bin/llc32

BUILD_DEPENDS+=		${LOCALBASE}/bin/opt32:${PORTSDIR}/devel/llvm32
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
USES+=		iconv

CONFIGURE_ARGS+=	--enable-executable-stripping
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

.if !defined(STANDALONE) || ${PORT_OPTIONS:MDYNAMIC}
RUN_DEPENDS+=	${dependencies}
.endif

.endif

.if defined(USE_GHC_NATIVE)
USES+=		perl5
USE_PERL5=	build
.endif

.if ${PORT_OPTIONS:MDOCS}
.if !defined(XMLDOCS)

.if defined(HADDOCK_AVAILABLE)
HADDOCK_OPTS=	# empty

.if ${PORT_OPTIONS:MHSCOLOUR}
BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.20.3
HSCOLOUR_DATADIR=	${LOCALBASE}/share/cabal/ghc-${GHC_VERSION}/hscolour-${HSCOLOUR_VERSION}
HADDOCK_OPTS+=		--hyperlink-source --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif # HSCOLOUR
.endif # HADDOCK_AVAILABLE

.endif

.if defined(XMLDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt

USES+=		gmake

.endif # !XMLDOCS

.endif # DOCS

__handle_datadir__=	--datadir='${DATADIR}' --datasubdir='' --docdir='${DOCSDIR}'

.if defined(HADDOCK_AVAILABLE) && !defined(XMLDOCS) && ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--haddock-options=-w --with-haddock=${HADDOCK_CMD}
.endif

.if ${PORT_OPTIONS:MDYNAMIC}
CONFIGURE_ARGS+=	--enable-shared --enable-executable-dynamic
CONFIGURE_ARGS+=	"--ghc-option=-optl -rpath" "--ghc-option=-optl ${CABAL_LIBDIR}/${DISTNAME}"
.else
CONFIGURE_ARGS+=	--disable-shared --disable-executable-dynamic
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

_BUILD_SETUP=	${GHC_CMD} -o ${SETUP_CMD} -package Cabal --make

.if !defined(METAPORT)
.if !target(do-configure)
do-configure:
	@if [ -f ${WRKSRC}/Setup.hs ]; then \
	    cd ${WRKSRC} && ${_BUILD_SETUP} Setup.hs; fi
	@if [ -f ${WRKSRC}/Setup.lhs ]; then \
	    cd ${WRKSRC} && ${_BUILD_SETUP} Setup.lhs; fi
	@if [ -f ${WRKSRC}/${SETUP_CMD} ]; then \
	    cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	    ${SETUP_CMD} configure --ghc --prefix=${PREFIX} \
		--extra-include-dirs="${LOCALBASE}/include" --extra-lib-dirs="${LOCALBASE}/lib" \
		${__handle_datadir__} ${CONFIGURE_ARGS}; \
	else \
	    ${ECHO_MSG} "===>  ${PKGNAME} configure fails: no setup program could be created."; \
	    exit 1; \
	fi

.if ${PORT_OPTIONS:MDOCS}
.if defined(XMLDOCS) && defined(USE_AUTOTOOLS)
	cd ${WRKSRC}/doc && ${AUTOCONF} && ./configure --prefix=${PREFIX}
.endif
.endif # DOCS
.endif # target(do-configure)
.endif # !METAPORT

.if !defined(METAPORT)
.if !target(do-build)
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SETUP_CMD} build
.if !defined(STANDALONE)
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SETUP_CMD} register --gen-script
.endif

.if ${PORT_OPTIONS:MDOCS}
.if defined(HADDOCK_AVAILABLE) && !defined(XMLDOCS) && !defined(STANDALONE) && ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SETUP_CMD} haddock ${HADDOCK_OPTS}
.endif # STANDALONE
.if defined(XMLDOCS)
	@(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} html)
.endif # XMLDOCS
.endif # DOCS
.endif # target(do-build)
.endif # !METAPORT

.if defined(MAN1)
.for man in ${MAN1}
PLIST_FILES+=	man/man1/${man}.gz
.endfor
.endif

.if defined(MAN5)
.for man in ${MAN5}
PLIST_FILES+=	man/man5/${man}.gz
.endfor
.endif

.if !defined(METAPORT)
.if !target(do-install)
do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SETUP_CMD} copy --destdir=${STAGEDIR}

.if !defined(STANDALONE)
	cd ${WRKSRC} && ${INSTALL_SCRIPT} register.sh ${STAGEDIR}${CABAL_LIBDIR}/${CABAL_LIBSUBDIR}/register.sh
.endif

.if !empty(INSTALL_PORTDATA)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PORTDATA}
.endif

.if !empty(INSTALL_PORTEXAMPLES) && ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PORTEXAMPLES}
.endif

.if defined(MAN1SRC)
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${MAN1SRC}/${man} ${STAGEDIR}${PREFIX}/man/man1
.endfor
.endif # MAN1SRC

.if ${PORT_OPTIONS:MDOCS}
.if !empty(XMLDOCS)
.for xmldoc in ${XMLDOCS}
	@(cd ${WRKSRC}/${xmldoc:C/:.*$//g} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/${xmldoc:C/^.*://g})
.endfor
.endif # XMLDOCS
.endif # DOCS
.endif # target(do-install)
.endif # !METAPORT

.if !target(post-install-script)
post-install-script:
	@for dir in ${CABAL_DIRS}; do if [ -d ${STAGEDIR}$${dir} ]; then ${FIND} -ds ${STAGEDIR}$${dir} \
		-type f -print | ${SED} -E -e 's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}; fi ; \
		if [ -d ${STAGEDIR}$${dir} ]; then ${FIND} -ds ${STAGEDIR}$${dir} \
		-type d -print | ${SED} -E -e 's,^${STAGEDIR}${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}; fi ; done
.if defined(EXECUTABLE)
.for exe in ${EXECUTABLE}
	@${ECHO_CMD} 'bin/${exe}' >>${TMPPLIST}
.endfor
.endif

.endif # target(post-install-script)

.if !defined(METAPORT)
add-plist-post: add-plist-cabal
add-plist-cabal:

.if !defined(STANDALONE)
	@${ECHO_CMD} '@unexec ${LOCALBASE}/bin/ghc-pkg unregister --force ${PORTNAME}-${PORTVERSION}' >> ${TMPPLIST}
.endif

.if defined(HADDOCK_AVAILABLE) && ${PORT_OPTIONS:MDOCS}
	@(${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/${GHC_LIB_DOCSDIR_REL}/${DISTNAME}' ; \
	  ${ECHO_CMD} '@unexec cd ${LOCALBASE}/${GHC_LIB_DOCSDIR_REL} && \
	    ${RM} -f doc-index*.html && ./gen_contents_index') >> ${TMPPLIST}
.endif

.if !defined(STANDALONE)
	@${ECHO_CMD} '@exec ${SH} %D/${CABAL_LIBDIR_REL}/${CABAL_LIBSUBDIR}/register.sh' >> ${TMPPLIST}
.endif

.if defined(HADDOCK_AVAILABLE) && ${PORT_OPTIONS:MDOCS}
	@(${ECHO_CMD} '@exec ${LN} -s ${DOCSDIR}/html ${LOCALBASE}/${GHC_LIB_DOCSDIR_REL}/${DISTNAME} && \
	  cd ${LOCALBASE}/${GHC_LIB_DOCSDIR_REL} && \
	  ${RM} -f doc-index*.html && ./gen_contents_index') >> ${TMPPLIST}
.endif

.endif # !METAPORT
