# New ports collection makefile for:   generator
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	generator
PORTVERSION=	0.35
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://www.squish.net/generator/files/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	SEGA Genesis emulator

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

PLIST_FILES=	bin/${PORTNAME}-gtk
USE_GNOME=	gtk12
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-gtk
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		RAZE "Use RAZE z80 emulation (only for i386)" on \
		SDL_AUDIO "Use SDL for audio" off

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

# Generator does not automatically determine the GCC version.

.if defined(WITH_OPTIMIZED_CFLAGS)
.	if ${OSVERSION} < 500035
CONFIGURE_ARGS+=	--with-gcc=2
.	elif ${OSVERSION} >= 500035
CONFIGURE_ARGS+=	--with-gcc=3
.	endif
.else
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
