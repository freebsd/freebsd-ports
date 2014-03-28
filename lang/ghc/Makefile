# Created by: Simon Marlow <simonmar@microsoft.com>
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	7.6.3
PORTREVISION=	3
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		${MASTER_SITE_LOCAL:S/$/:boot/}
MASTER_SITE_SUBDIR=	pgj/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for the functional language Haskell

ONLY_FOR_ARCHS=	i386 amd64

MAKE_JOBS_NUMBER_LIMIT=		4

GHC_VERSION=		${PORTVERSION}
HSCOLOUR_VERSION=	1.20.3

DATADIR=	${PREFIX}/share/ghc-${GHC_VERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/ghc-${GHC_VERSION}

CONFLICTS=	ghc-6.8.* ghc-6.10.* ghc-6.12.* ghc-7.0.* ghc-7.2.* ghc-7.4.*

USE_BZIP2=	yes
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp

USE_AUTOTOOLS=		autoconf autoheader
USE_PERL5=		build
USES=			gmake iconv perl5 ncurses
USE_BINUTILS=		yes
USE_GCC=		yes

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ENV=	LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8

# The configure process accepts,filters and canonicalises
# the CONFIGURE_TARGET variable. You can read the files
# ${WRKSRC}/configure and ${WRKSRC}/config.sub.
# This is better fixed in the ${WRKSRC}/mk/build.mk.
# You can view below.
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		PROFILE DYNAMIC LLVM DOCS
OPTIONS_DEFAULT=	PROFILE DYNAMIC DOCS

BOOT_DESC=		Use installed GHC for bootstrapping
BOOTH_DESC=		Use installed HsColour for bootstrapping
PROFILE_DESC=		Add support for performance profiling
DYNAMIC_DESC=		Add support for dynamic linking
LLVM_DESC=		Add support for generating code via LLVM
DOCS_DESC=		Install HTML documentation

LOCALBASE?=	/usr/local

.if exists(${LOCALBASE}/bin/ghc)
OPTIONS_DEFINE+=	BOOT
.endif

.if exists(${LOCALBASE}/bin/HsColour)
OPTIONS_DEFINE+=	BOOTH
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDYNAMIC}
LIB_DEPENDS+=	ffi.6:${PORTSDIR}/devel/libffi
.endif

.if empty(PORT_OPTIONS:MBOOT)

.if ${OSVERSION} >= 1000043
BOOT_GHC_VERSION=	7.6.3
.else
BOOT_GHC_VERSION=	7.4.1
.endif

EXTRA_PATCHES=		${PATCHDIR}/nopatch-.._ghc-${BOOT_GHC_VERSION}-boot_rts_package.conf.in

.if ${ARCH} == "i386"

.if ${OSVERSION} >= 1000043
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-i386-freebsd10-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 900000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-i386-freebsd9-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 800000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-i386-freebsd8-boot${EXTRACT_SUFX}:boot
.else
IGNORE=		unsupported
.endif

.elif ${ARCH} == "amd64"

.if ${OSVERSION} >= 1000043
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-amd64-freebsd10-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 900000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-amd64-freebsd9-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 800000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-amd64-freebsd8-boot${EXTRACT_SUFX}:boot
.else
IGNORE=		unsupported
.endif

.endif

.endif # MBOOT

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
GHC_LIBDIR=	${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION}
GHC_LIBDIR_REL=	lib/ghc-${GHC_VERSION}

PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} GHC_LIBDIR=${GHC_LIBDIR_REL}

HACKAGE_SITE?=		http://hackage.haskell.org/package/

CONFIGURE_ARGS=		--with-gcc=${CC} \
			--with-ld=${LD} \
			--with-gmp-includes=${LOCALBASE}/include \
			--with-gmp-libraries=${LOCALBASE}/lib

.if ${OSVERSION} < 1000043
CONFIGURE_ARGS+=	--with-iconv-includes=${LOCALBASE}/include \
			--with-iconv-libraries=${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MDYNAMIC}
CONFIGURE_ARGS+=	--with-system-libffi \
			--with-ffi-includes=${LOCALBASE}/include \
			--with-ffi-libraries=${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MLLVM}
BUILD_DEPENDS+=		${LOCALBASE}/bin/opt32:${PORTSDIR}/devel/llvm32
RUN_DEPENDS+=		${LOCALBASE}/bin/opt32:${PORTSDIR}/devel/llvm32

CONFIGURE_ARGS+=	--with-opt=${LOCALBASE}/bin/opt32 \
			--with-llc=${LOCALBASE}/bin/llc32
.endif

.if empty(PORT_OPTIONS:MBOOT)

BOOT_DIR=	${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}
BOOT_GHC-PKG=	${BOOT_DIR}/bin/ghc-pkg-${BOOT_GHC_VERSION}
BOOT_HSC2HS=	${BOOT_DIR}/bin/hsc2hs

SLAVE_CMD=	${SETENV} PATH=${BOOT_DIR}/bin:${PATH}

CONFIGURE_ARGS_BOOT=	--prefix=${BOOT_DIR} --with-gcc=${CC}
CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC}

.else # MBOOT

SLAVE_CMD=	# empty

CONFIGURE_ARGS+=	--with-ghc=${LOCALBASE}/bin/ghc

.endif # MBOOT

# libgmp:
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp
MAKE_ENV+=	TMPDIR=${TMPDIR}

# Defining with documentation:
# An in place installation and registration of hscolour will be
# activated. In this way it's possible to use it directly into
# the build tree, without needing to install it. At the end
# you could view the output of: ${BOOT_GHC} describe hscolour

.if ${PORT_OPTIONS:MDOCS}

.if empty(PORT_OPTIONS:MBOOTH)

MASTER_SITES+=	${HACKAGE_SITE}hscolour-${HSCOLOUR_VERSION}/:docs
DISTFILES+=	hscolour-${HSCOLOUR_VERSION}.tar.gz:docs

EXTRACT_ONLY=	${_DISTFILES:C/hscolour.*$//g}

.endif # MBOOTH

.if empty(PORT_OPTIONS:MBOOTH)

SLAVES_PREFIX=		${WRKDIR}/slaves_prefix
SLAVES_WRKDIRPREFIX=	${WRKDIR}/slaves_wrkdirprefix

MAKE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}
MAKE_ENV+=	LC_ALL=en_US.UTF-8
CONFIGURE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}

.endif # MBOOTH

BUILD_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/html:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
.endif

post-extract:
	@${ECHO} >> ${WRKSRC}/mk/build.mk "docdir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "htmldir = ${PREFIX}/share/doc/ghc-${GHC_VERSION}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "mandir = ${PREFIX}/man"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "infodir = ${PREFIX}/info"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays = v"
.if ${PORT_OPTIONS:MPROFILE}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays += p"
.endif
.if ${PORT_OPTIONS:MDYNAMIC}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "GhcLibWays += dyn"
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "XMLDocWays = html"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HADDOCK_DOCS = YES"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HSCOLOUR_SRCS = YES"
.else
	@${ECHO} >> ${WRKSRC}/mk/build.mk "XMLDocWays ="
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HADDOCK_DOCS ="
	@${ECHO} >> ${WRKSRC}/mk/build.mk "HSCOLOUR_SRCS ="
.endif
.if ${PORT_OPTIONS:MBOOT}
	@${ECHO} >> ${WRKSRC}/mk/build.mk "BSD_PATH_TO_HSC2HS = ${LOCALBASE}/bin/hsc2hs"
.else
	@${ECHO} >> ${WRKSRC}/mk/build.mk "BSD_PATH_TO_HSC2HS = ${BOOT_HSC2HS}"
.endif
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_HC_OPTS += -I${NCURSESINC} -L${NCURSESLIB} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_CC_OPTS += ${CFLAGS}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_HSC2HS_OPTS += -I${LOCALBASE}/include --lflag=-L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_LD_OPTS += -L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-include-dirs=${LOCALBASE}/include"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-lib-dirs=${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "libraries/terminfo_CONFIGURE_OPTS += --configure-option=--with-curses-includes=${NCURSESINC} --configure-option=--with-curses-libraries=${NCURSESLIB}"
#	@${ECHO} >> ${WRKSRC}/mk/build.mk "BIN_DIST_NAME = ghc-\$$(ProjectVersion)-boot"
#	@${ECHO} >> ${WRKSRC}/mk/build.mk "BIN_DIST_TAR  = ghc-\$$(ProjectVersion)-amd64-ash0-freebsd8-boot.tar"

post-install-script:
	@${FIND} -ds ${GHC_LIBDIR} -type f -print | ${SED} -E -e \
		'/^${GHC_LIBDIR:C/\//\\\//g}\/package.conf.d\/package\.cache/d' -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DOCSDIR} -type f -print | ${SED} -E -e \
		'/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/doc-index-[^.]+\.html/d' -e \
		'/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/index[^\/.]*\.html/d' -e \
		'/^${STAGEDIR:C/\//\\\//g}${DOCSDIR:C/\//\\\//g}\/html\/libraries\/[^\/]+\.png/d' -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	# Cleanup the indexen created by gen_contents_index
	@${ECHO} "@unexec ${RM} -f %D/${DOCSDIR_REL}/html/libraries/doc-index-*.html" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RM} -f %D/${DOCSDIR_REL}/html/libraries/index*.html" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RM} -f %D/${DOCSDIR_REL}/html/libraries/*.png" >> ${TMPPLIST}
.endif
	@${ECHO} '@unexec ${RM} -f %D/${GHC_LIBDIR_REL}/package.conf.d/package.cache' >>${TMPPLIST}
	@${ECHO} "@exec %D/bin/ghc-pkg recache" >>${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} '@exec ${SH} -c "cd %D/${DOCSDIR_REL}/html/libraries && ./gen_contents_index"' >> ${TMPPLIST}
.endif
	@${FIND} -ds ${STAGEDIR}${DOCSDIR} -type d -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
	@${FIND} -ds ${GHC_LIBDIR} -type d -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}

#post-build:
#	@(cd ${WRKSRC} && ${GMAKE} binary-dist)
#
#do-install:
#	@${NONE}

post-patch:
# Hack don't to install the internal haddock.
	@${REINPLACE_CMD} -e 's+\(DO_NOT_INSTALL =\)+\1 haddock+' \
		${WRKSRC}/utils/Makefile

.if ${PORT_OPTIONS:MBOOT}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/rts/package.conf.in \
		${WRKSRC}/libraries/Makefile
.else
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/../ghc-${BOOT_GHC_VERSION}-boot/rts/package.conf.in \
		${WRKSRC}/rts/package.conf.in \
		${WRKSRC}/libraries/Makefile
.endif

	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure

pre-configure:
	@${MKDIR} ${TMPDIR}
.if empty(PORT_OPTIONS:MBOOT)
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS_BOOT})
	@(cd ${BOOT_DIR} && PACKAGES='' ${GMAKE} install)
.endif

# Defining with documentation:
# Defining "SLAVE" in devel/hs-haddock and print/hs-hscolour flips the building process
# functionally to this port.
.if ${PORT_OPTIONS:MDOCS} && empty(PORT_OPTIONS:MBOOTH)
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "  WARNING: Now HsColour will be built, the respective port will not   "
	@${ECHO_MSG} "           be installed, but an in-place installation and             "
	@${ECHO_MSG} "           registration of both takes place.                          "
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} ""
	@sleep 3

	@${MKDIR} ${SLAVES_PREFIX}
	@${MKDIR} ${SLAVES_WRKDIRPREFIX}

	@(cd ${SLAVES_WRKDIRPREFIX} && \
		${TAR} xvf ${DISTDIR}/hscolour-${HSCOLOUR_VERSION}.tar.gz && \
		cd hscolour-${HSCOLOUR_VERSION} && \
		${SLAVE_CMD} ghc --make -o Setup Setup.hs -package Cabal && \
		${SLAVE_CMD} ./Setup configure --ghc --prefix=${SLAVES_PREFIX} && \
		${SLAVE_CMD} ./Setup build && \
		${SLAVE_CMD} ./Setup install)
.endif

post-install:
	# cabalised hs-foo-ghc ports
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cabal/ghc-${GHC_VERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/cabal/ghc-${GHC_VERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/cabal/ghc-${GHC_VERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/cabal/ghc-${GHC_VERSION}
	@${RM} -f ${STAGEDIR}${PREFIX}/bin/haddock
.if ${PORT_OPTIONS:MDOCS}
	@${LN} -sf haddock-ghc-${GHC_VERSION} ${STAGEDIR}${PREFIX}/bin/haddock
.endif

.include <bsd.port.mk>
