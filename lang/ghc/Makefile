# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	6.4
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		http://www.haskell.org/ghc/dist/${PORTVERSION}/FreeBSD/:boot

ONLY_FOR_ARCHS=	i386

SRC_DIST=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source
BOOT_DIST=	ghc-${PORTVERSION}-i386-unknown-freebsd-boot${EXTRACT_SUFX}:boot
BOOT_DIST5=	ghc-${PORTVERSION}-i386-unknown-freebsd5-boot${EXTRACT_SUFX}:boot

USE_BZIP2=	yes
.include <bsd.port.pre.mk>

DISTFILES=	${SRC_DIST}

.if ${OSVERSION} < 500000
DISTFILES+=	${BOOT_DIST}
.else
DISTFILES+=	${BOOT_DIST5}
.endif

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

MAINTAINER=	simonmar@microsoft.com
COMMENT=	A Compiler for the functional language Haskell

USE_PERL5=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	GHC_VERSION=${PORTVERSION}
.if defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

# This port builds by downloading a minimal binary distribution of GHC and
# using that to bootstrap.
BOOT_DIR=	${WRKDIR}/ghc-${PORTVERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/i386-unknown-freebsd/ghc-${PORTVERSION}

CONFIGURE_ARGS=	--with-ghc=${BOOT_GHC}  --with-gcc=${CC}
# specifying CONFIGURE_TARGET doesn't work for some reason.
CONFIGURE_TARGET=
# libgmp:
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp
MAKE_ENV+=	TMPDIR=${TMPDIR}

# Just do a stage1 build
ALL_TARGET=	stage1
MAKE_ENV += stage=1

pre-everything::
.if !defined(WITHOUT_PROFILE)
	@${ECHO_CMD} "To build GHC without profiling libraries,"
	@${ECHO_CMD} "hit Ctrl-C now and restart with 'make"
	@${ECHO_CMD} "WITHOUT_PROFILE=YES'."
.else
	@${ECHO_CMD} "Building GHC without profiling libraries."
.endif

.if defined(WITHOUT_PROFILE)
post-extract:
	@${ECHO} >>${WRKSRC}/mk/build.mk GhcLibWays=
.endif

post-patch:
	@${REINPLACE_CMD} s+%%LOCALBASE%%+${LOCALBASE}+ \
		${WRKSRC}/ghc/rts/package.conf.in

pre-configure:
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
	@(cd ${BOOT_DIR} && ${MAKE} in-place)

pre-build:
	@${MKDIR} ${TMPDIR}

.include <bsd.port.post.mk>
