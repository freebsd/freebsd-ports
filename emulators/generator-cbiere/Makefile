# New ports collection makefile for:   emulators/generator-cbiere
# Date created:        7 Jun 2005
# Whom:                Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.35
CATEGORIES=	emulators
MASTER_SITES=	http://www.ghostwhitecrab.com/generator/
PKGNAMESUFFIX=	-cbiere
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	SEGA Genesis emulator

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
USE_GNOME=	gtk12

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		RAZE "Use RAZE z80 emulation (only for i386)" on \
		SDL_AUDIO "Use SDL for audio" off

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--program-transform-name=s/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-gtk

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}-gtk

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.pre.mk>

.if ${ARCH} != "amd64" && ${ARCH} != "i386"
USE_REINPLACE=	yes

post-patch:
# These architectures do not support "-minline-all-stringops"
	@${REINPLACE_CMD} -e 's|-minline-all-stringops||g' \
				${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if ${ARCH} == "alpha"
# "-ffast-math" does not work on alpha
	@${REINPLACE_CMD} -e 's|-ffast-math||g' \
				${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.endif

# Generator needs GCC 2.95.x or GCC >= 3.4.2 to work properly.
# Generator-CBiere automatically determines the GCC version.

.if ${OSVERSION} < 400012
# GCC < 2.95 is in the base system.
USE_GCC=		2.95
.endif

.if ${OSVERSION} >= 500035 && ${OSVERSION} < 502126
# GCC > 2.95 (3.X) && GCC < 3.4.2 is in the base system.
USE_GCC=		3.4
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--without-gcc
.endif

.if defined(WITH_RAZE) && ${ARCH} == "i386"
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-raze
.else
CONFIGURE_ARGS+=	--with-cmz80
.endif

.if defined(WITH_SDL_AUDIO)
CONFIGURE_ARGS+=	--with-sdl-audio
.endif

.include <bsd.port.post.mk>
