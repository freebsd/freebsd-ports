PORTNAME=	syncterm
DISTVERSION=	1.6
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	shurd@freebsd.org
COMMENT=	ANSI-BBS terminal which supports telnet, rlogin, and SSH
WWW=		https://syncterm.bbsdev.net/

LICENSE=	GPLv2

USES=		gmake perl5 tar:tgz
USE_PERL5=	build
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	INSTALL_EXE="${INSTALL_PROGRAM}" \
		MANPREFIX="${PREFIX}/share" \
		PREFIX="${PREFIX}" \
		RELEASE=1 \
		WITHOUT_ALSA_SOUND=yes
ALL_TARGET=	${PORTNAME}

CFLAGS+=	-I../xpdev
NO_CCACHE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		JXL PORTAUDIO PULSEAUDIO SDL X11
OPTIONS_DEFAULT=	JXL X11

JXL_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libjxl.pc:graphics/libjxl
JXL_USES=		pkgconfig
JXL_MAKE_ARGS_OFF=	WITHOUT_JPEG_XL=1

PORTAUDIO_BUILD_DEPENDS=	${LOCALBASE}/include/portaudio.h:audio/portaudio
PORTAUDIO_MAKE_ARGS_OFF=	WITHOUT_PORTAUDIO=1

PULSEAUDIO_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpulse-simple.pc:audio/pulseaudio
PULSEAUDIO_USES=		pkgconfig
PULSEAUDIO_MAKE_ARGS_OFF=	NO_PULSEAUDIO=1

SDL_BUILD_DEPENDS=	${LOCALBASE}/bin/sdl2-config:devel/sdl20
SDL_MAKE_ARGS=		USE_SDL=1 \
			USE_SDL_AUDIO=1
SDL_MAKE_ARGS_OFF=	WITHOUT_SDL=1

X11_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/x11.pc:x11/libX11 \
			${LOCALBASE}/libdata/pkgconfig/xinerama.pc:x11/libXinerama \
			${LOCALBASE}/libdata/pkgconfig/xrandr.pc:x11/libXrandr \
			${LOCALBASE}/libdata/pkgconfig/xrender.pc:x11/libXrender
X11_USES=		pkgconfig
X11_MAKE_ARGS_OFF=	NO_X=1

.include <bsd.port.mk>
