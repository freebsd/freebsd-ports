PORTNAME=	syncterm
DISTVERSION=	1.8
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	shurd@freebsd.org
COMMENT=	ANSI-BBS terminal which supports telnet, rlogin, and SSH
WWW=		https://syncterm.bbsdev.net/

LICENSE=	GPLv2

USES=		cmake perl5 tar:tgz
USE_PERL5=	build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		JXL PORTAUDIO PULSEAUDIO SDL WAYLAND X11
OPTIONS_DEFAULT=	JXL WAYLAND X11

JXL_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libjxl.pc:graphics/libjxl
JXL_USES=		pkgconfig
JXL_CMAKE_OFF=		-DWITHOUT_JPEG_XL=ON

PORTAUDIO_BUILD_DEPENDS=	${LOCALBASE}/include/portaudio.h:audio/portaudio
PORTAUDIO_CMAKE_OFF=		-DWITHOUT_PORTAUDIO=ON

PULSEAUDIO_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libpulse-simple.pc:audio/pulseaudio
PULSEAUDIO_USES=		pkgconfig
PULSEAUDIO_CMAKE_OFF=		-DWITHOUT_PULSEAUDIO=ON

SDL_BUILD_DEPENDS=	${LOCALBASE}/bin/sdl2-config:devel/sdl20
SDL_CMAKE_OFF=		-DWITHOUT_SDL=ON

WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/wayland-client.pc:graphics/wayland
WAYLAND_USES=		pkgconfig
WAYLAND_CMAKE_OFF=	-DWITHOUT_WAYLAND=ON

X11_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/x11.pc:x11/libX11 \
			${LOCALBASE}/libdata/pkgconfig/xinerama.pc:x11/libXinerama \
			${LOCALBASE}/libdata/pkgconfig/xrandr.pc:x11/libXrandr \
			${LOCALBASE}/libdata/pkgconfig/xrender.pc:x11/libXrender
X11_USES=		pkgconfig
X11_CMAKE_OFF=		-DWITHOUT_X11=ON

.include <bsd.port.mk>
