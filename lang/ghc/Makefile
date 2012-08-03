# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	7.4.1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		${MASTER_SITE_LOCAL:S/$/:boot/}
MASTER_SITE_SUBDIR=	pgj/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Compiler for the functional language Haskell

ONLY_FOR_ARCHS=	i386 amd64

GHC_VERSION=	${PORTVERSION}
BOOT_GHC_VERSION=	7.4.1
HSCOLOUR_VERSION=	1.19

DATADIR=	${PREFIX}/share/ghc-${GHC_VERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/ghc-${GHC_VERSION}

CONFLICTS=	ghc-6.8.* ghc-6.10.* ghc-6.12.* ghc-7.0.* ghc-7.2.*

USE_BZIP2=	yes
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
USE_ICONV=	yes

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ENV=	LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8

# The configure process accepts,filters and canonicalises
# the CONFIGURE_TARGET variable. You can read the files
# ${WRKSRC}/configure and ${WRKSRC}/config.sub.
# This is better fixed in the ${WRKSRC}/mk/build.mk.
# You can view below.
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		PROFILE DYNAMIC DOCS
OPTIONS_DEFAULT=	PROFILE DYNAMIC DOCS

PROFILE_DESC=		Add support for performance profiling
DYNAMIC_DESC=		Add support for dynamic linking
DOCS_DESC=		Install HTML documentation

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"

.if ${OSVERSION} >= 900000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-i386-freebsd9-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 800000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-i386-freebsd8-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 700000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-i386-freebsd7-boot${EXTRACT_SUFX}:boot
.else
IGNORE=		unsupported
.endif

.elif ${ARCH} == "amd64"

.if ${OSVERSION} >= 900000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-amd64-freebsd9-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 800000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-amd64-freebsd8-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 700000
DISTFILES+=	ghc-${BOOT_GHC_VERSION}-amd64-freebsd7-boot${EXTRACT_SUFX}:boot
.else
IGNORE=		unsupported
.endif

.endif

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
GHC_LIBDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}
GHC_LIBDIR_REL=	lib/ghc-${GHC_VERSION}

PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} GHC_LIBDIR=${GHC_LIBDIR_REL}

# This port builds by downloading a minimal binary distribution of GHC and
# using that to bootstrap.
BOOT_DIR=	${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}
BOOT_GHC-PKG=	${BOOT_DIR}/bin/ghc-pkg-${BOOT_GHC_VERSION}
BOOT_HSC2HS=	${BOOT_DIR}/bin/hsc2hs
HACKAGE_SITE?=		http://hackage.haskell.org/
HACKAGE_ARCH?=		packages/archive/

CONFIGURE_ARGS_BOOT=	--prefix=${BOOT_DIR} CC=${CC}
CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC} --with-gcc=${CC} \
			--with-gmp-includes=${LOCALBASE}/include \
			--with-gmp-libraries=${LOCALBASE}/lib \
			--with-iconv-includes=${LOCALBASE}/include \
			--with-iconv-libraries=${LOCALBASE}/lib

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

MASTER_SITES+=	${HACKAGE_SITE}${HACKAGE_ARCH}hscolour/${HSCOLOUR_VERSION}/:docs
DISTFILES+=	hscolour-${HSCOLOUR_VERSION}.tar.gz:docs

EXTRACT_ONLY=	${_DISTFILES:C/hscolour.*$//g}

MAN1=		ghc.1

SLAVES_PREFIX=		${WRKDIR}/slaves_prefix
SLAVES_WRKDIRPREFIX=	${WRKDIR}/slaves_wrkdirprefix
SLAVE_CMD=	${SETENV} PATH=${BOOT_DIR}/bin:${PATH}

MAKE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}
MAKE_ENV+=	LC_ALL=en_US.UTF-8
CONFIGURE_ENV+=	PATH=${SLAVES_PREFIX}/bin:${PATH}

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
	@${ECHO} >> ${WRKSRC}/mk/build.mk "BSD_PATH_TO_HSC2HS = ${BOOT_HSC2HS}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_HC_OPTS += -I${LOCALBASE}/include -L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "SRC_CC_OPTS += ${CFLAGS}"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_HSC2HS_OPTS += -I${LOCALBASE}/include --lflag=-L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_LD_OPTS += -L${LOCALBASE}/lib"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-include-dirs=${LOCALBASE}/include"
	@${ECHO} >> ${WRKSRC}/mk/build.mk "EXTRA_CABAL_CONFIGURE_FLAGS += --extra-lib-dirs=${LOCALBASE}/lib"
#	@${ECHO} >> ${WRKSRC}/mk/build.mk "BIN_DIST_NAME = ghc-\$$(ProjectVersion)-boot"
#	@${ECHO} >> ${WRKSRC}/mk/build.mk "BIN_DIST_TAR  = ghc-\$$(ProjectVersion)-amd64-ash0-freebsd8-boot.tar"

post-install-script:
	@${FIND} -ds ${GHC_LIBDIR} -type f -print | ${SED} -E -e \
		'/^${GHC_LIBDIR:C/\//\\\//g}\/package.conf.d\/package\.cache/d' -e \
		's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${DOCSDIR} -type f -print | ${SED} -E -e \
		'/^${DOCSDIR:C/\//\\\//g}\/html\/libraries\/doc-index-[^.]+\.html/d' -e \
		'/^${DOCSDIR:C/\//\\\//g}\/html\/libraries\/index[^\/.]*\.html/d' -e \
		'/^${DOCSDIR:C/\//\\\//g}\/html\/libraries\/[^\/]+\.png/d' -e \
		's,^${PREFIX}/?,,' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	# Cleanup the indexen created by gen_contents_index
	@${ECHO} "@unexec ${RM} -f %D/${DOCSDIR_REL}/html/libraries/doc-index-*.html" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RM} -f %D/${DOCSDIR_REL}/html/libraries/index*.html" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RM} -f %D/${DOCSDIR_REL}/html/libraries/*.png" >> ${TMPPLIST}
.endif
	@${ECHO} "@exec %D/bin/ghc-pkg recache" >>${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} '@exec ${SH} -c "cd %D/${DOCSDIR_REL}/html/libraries && ./gen_contents_index"' >> ${TMPPLIST}
.endif
	@${ECHO} '@unexec ${RM} -f %D/${GHC_LIBDIR_REL}/package.conf.d/package.cache' >>${TMPPLIST}
	@${FIND} -ds ${DOCSDIR} -type d -print | ${SED} -E -e \
		's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
	@${FIND} -ds ${GHC_LIBDIR} -type d -print | ${SED} -E -e \
		's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}

#post-build:
#	@(cd ${WRKSRC} && ${GMAKE} binary-dist)
#
#do-install:
#	@${NONE}

post-patch:
# Hack don't to install the internal haddock.
	@${REINPLACE_CMD} -e 's+\(DO_NOT_INSTALL =\)+\1 haddock+' \
		${WRKSRC}/utils/Makefile

	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/../ghc-${BOOT_GHC_VERSION}-boot/rts/package.conf.in \
		${WRKSRC}/rts/package.conf.in \
		${WRKSRC}/libraries/Makefile

	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure

pre-configure:
	@${MKDIR} ${TMPDIR}
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS_BOOT})
	@(cd ${BOOT_DIR} && PACKAGES='' ${GMAKE} install)

# Defining with documentation:
# Defining "SLAVE" in devel/hs-haddock and print/hs-hscolour flips the building process
# functionally to this port.
.if ${PORT_OPTIONS:MDOCS}
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
	@${MKDIR} ${GHC_LIBDIR}/cabal
	@${MKDIR} ${DOCSDIR}/cabal
	@${MKDIR} ${EXAMPLESDIR}/cabal
	@${MKDIR} ${DATADIR}/cabal
.if ${PORT_OPTIONS:MDOCS}
	cd ${DOCSDIR}/html/libraries && ./gen_contents_index
.endif
	@${RM} -f ${PREFIX}/bin/haddock
.if ${PORT_OPTIONS:MDOCS}
	@${LN} -sf ${PREFIX}/bin/haddock-ghc-${GHC_VERSION} ${PREFIX}/bin/haddock
.endif
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
