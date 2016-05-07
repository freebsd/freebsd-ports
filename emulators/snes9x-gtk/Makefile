# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	snes9x
PORTVERSION=	1.53r81
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://snes9x-gtk.googlecode.com/files/
PKGNAMESUFFIX=	-gtk
DISTNAME=	snes9x-1.53-src

MAINTAINER=	root@cooltrainer.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

LICENSE=	Snes9x
LICENSE_NAME=	Snes9x License
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/docs/snes9x-license.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libpng.so:graphics/png

USE_XORG=	x11 sm ice xext
USES=		gettext gmake perl5 desktop-file-utils pkgconfig tar:bzip2 desktop-file-utils
USE_GNOME=	gtk20 intltool libglade2 libxml2
GNU_CONFIGURE=	yes
USE_SDL=	sdl2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${DISTNAME}/gtk
NO_CDROM=	Commercial users must seek permission from copyright holders.

OPTIONS_DEFINE=	DEBUG OPENGL JMA NETPLAY XV XRANDR ALSA PORTAUDIO PULSEAUDIO
OPTIONS_DEFAULT=	JMA NETPLAY XV XRANDR
JMA_DESC=	Enable JMA archive decompression support
NETPLAY_DESC=	Enable network support
XV_DESC=	Enable XVideo output on GTK
XRANDR_DESC=	Enable XRandR support on GTK
PORTAUDIO_DESC=	Enable PortAudio support
GTK2_DESC=	Use GTK 2.x interface toolkit

DEBUG_CONFIGURE_WITH=	debug
OPENGL_CONFIGURE_WITH=	opengl
OPENGL_USE=	GL=glu
JMA_CONFIGURE_WITH=	jma-decomp
NETPLAY_CONFIGURE_WITH=	netplay
XV_CONFIGURE_WITH=	xv
XV_USE=	XORG=xv
XRANDR_CONFIGURE_WITH=	xrandr
XRANDR_USE=	XORG=xrandr
ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_USES=	compiler:c++11-lang
PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so.2:audio/portaudio2
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

PLIST_FILES=	bin/snes9x-gtk \
		share/pixmaps/snes9x.svg \
		share/applications/snes9x.desktop

.include <bsd.port.pre.mk>

.if exists(/usr/lib/libusbhid.a)
CONFIGURE_ARGS+=	--with-joystick
.else
CONFIGURE_ARGS+=	--without-joystick
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.post.mk>
