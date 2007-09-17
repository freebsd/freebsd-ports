# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	6.6.1
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		http://www.haskell.org/ghc/dist/${PORTVERSION}/FreeBSD/:boot \
		${MASTER_SITE_LOCAL:S/$/:boot/}
MASTER_SITE_SUBDIR=vs/ghcdist/${PORTVERSION}/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source \
		ghc-${PORTVERSION}-src-extralibs${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Compiler for the functional language Haskell

ONLY_FOR_ARCHS=	i386

BOOT_DIST4=	ghc-${PORTVERSION}-i386-unknown-freebsd4-boot${EXTRACT_SUFX}:boot
BOOT_DIST5=	ghc-${PORTVERSION}-i386-unknown-freebsd5-boot${EXTRACT_SUFX}:boot
BOOT_DIST=	ghc-${PORTVERSION}-i386-unknown-freebsd6-boot${EXTRACT_SUFX}:boot

USE_BZIP2=	yes

OPTIONS=	PROFILE "Compile for profiling as well" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
#DISTFILES+=	${BOOT_DIST4}
IGNORE=		unsupported at the moment
.else
.if ${OSVERSION} >= 600000
DISTFILES+=	${BOOT_DIST}
.else
IGNORE=		unsupported at the moment
#DISTFILES+=	${BOOT_DIST5}
.endif
.endif
.if ${OSVERSION} >= 700000
IGNORE=		unsupported at the moment
.endif

USE_AUTOTOOLS=	autoconf:259:env
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB+=	GHC_VERSION=${PORTVERSION}
.if defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

# This port builds by downloading a minimal binary distribution of GHC and
# using that to bootstrap.
BOOT_DIR=	${WRKDIR}/ghc-${PORTVERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/i386-unknown-freebsd/ghc-${PORTVERSION}

CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC}  --with-gcc=${CC}
# specifying CONFIGURE_TARGET doesn't work for some reason.
CONFIGURE_TARGET=
# libgmp:
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp
MAKE_ENV+=	TMPDIR=${TMPDIR}
EXCLUDELIBS=	ALUT GLUT HGL OpenAL OpenGL X11

post-extract:
.if defined(WITHOUT_PROFILE)
	@${ECHO} >>${WRKSRC}/mk/build.mk GhcLibWays=
.endif
	@cd ${WRKSRC}/libraries && ${RM} -rf ${EXCLUDELIBS}

post-patch:
	@${REINPLACE_CMD} s+%%LOCALBASE%%+${LOCALBASE}+ \
		${WRKSRC}/rts/package.conf.in
	${REINPLACE_CMD} s+/usr/local/lib/ghc-6.6+${BOOT_DIR}/lib/i386-unknown-freebsd+ \
		${BOOT_DIR}/bin/i386-unknown-freebsd/*.sh

pre-configure:
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
	@(cd ${BOOT_DIR} && ${MAKE} in-place)

pre-build:
	@${MKDIR} ${TMPDIR}

post-install:
	@${RMDIR} ${PREFIX}/lib/ghc-${PORTVERSION}/imports/cbits	# empty/unused
	@${MKDIR} ${PREFIX}/lib/ghc-${PORTVERSION}/cabal		# cabalised hs-foo-ghc ports

.include <bsd.port.post.mk>
