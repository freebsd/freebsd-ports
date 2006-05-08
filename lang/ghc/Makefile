# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	6.4.2
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		http://www.haskell.org/ghc/dist/${PORTVERSION}/FreeBSD/:boot
PATCH_SITES=	http://www-i2.informatik.rwth-aachen.de/~stolz/FreeBSD/
PATCHFILES=	patch-ghc-libraries_OpenAL.diff

ONLY_FOR_ARCHS=	i386

SRC_DIST=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source
BOOT_DIST4=	ghc-${PORTVERSION}-i386-unknown-freebsd4-boot${EXTRACT_SUFX}:boot
BOOT_DIST=	ghc-${PORTVERSION}-i386-unknown-freebsd6-boot${EXTRACT_SUFX}:boot

USE_BZIP2=	yes

OPTIONS=	PROFILE "Compile for profiling as well" on

.include <bsd.port.pre.mk>

DISTFILES=	${SRC_DIST}

.if ${OSVERSION} < 500000
DISTFILES+=	${BOOT_DIST4}
IGNORE=		unsupported at the moment
.else
DISTFILES+=	${BOOT_DIST}
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif
.endif

.if ${PERL_LEVEL} < 500600
IGNORE=		requires newer version of perl
.endif

USE_AUTOTOOLS=	autoconf:259:env
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4 \
		readline.5:${PORTSDIR}/devel/readline

MAINTAINER=	simonmar@microsoft.com
COMMENT=	A Compiler for the functional language Haskell

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x --without-x11 --without-hgl --without-opengl --without-glut
PLIST_SUB+=	X11="@comment "
PKGNAMESUFFIX=	-nox11
.else
LIB_DEPENDS+=	glut.4:${PORTSDIR}/graphics/libglut
USE_GL=		yes
PLIST_SUB+=	X11=""
.endif

.if defined(WITH_OPENAL)
BROKEN=		Unsupported/does not build
PLIST_SUB+=	OPENAL=""
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
CONFIGURE_ARGS+=--enable-openal
.else
CONFIGURE_ARGS+=--without-openal
PLIST_SUB+=	OPENAL="@comment "
.endif

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

# Just do a stage1 build
ALL_TARGET=	stage1
MAKE_ENV += stage=1

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
