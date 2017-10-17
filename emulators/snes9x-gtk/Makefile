# Created by: okeeblow <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	snes9x
PORTVERSION=	1.54.1
PORTREVISION=	3
CATEGORIES=	emulators
PKGNAMESUFFIX=	-gtk

MAINTAINER=	root@cooltrainer.org
COMMENT=	Super Nintendo Entertainment System (SNES) Emulator

LICENSE=	Snes9x
LICENSE_NAME=	Snes9x License
LICENSE_FILE=	${WRKSRC}/../docs/snes9x-license.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libpng.so:graphics/png

BROKEN_powerpc64=	fails to configure: C compiler cannot create executables

USE_GITHUB=	yes
GH_ACCOUNT=	snes9xgit

USES=		autoreconf desktop-file-utils gettext gmake \
		localbase perl5 pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool libxml2
USE_SDL=	sdl2
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
LDFLAGS+=	-Wl,--as-needed

PATCH_WRKSRC=	${WRKSRC}/..
WRKSRC_SUBDIR=	gtk
NO_CDROM=	Commercial users must seek permission from copyright holders.

OPTIONS_DEFINE=		DEBUG JMA NETPLAY
OPTIONS_GROUP=		SOUND VIDEO
OPTIONS_GROUP_SOUND=	ALSA PORTAUDIO PULSEAUDIO
OPTIONS_GROUP_VIDEO=	OPENGL XRANDR XVIDEO
OPTIONS_DEFAULT=	JMA NETPLAY XVIDEO XRANDR

DEBUG_CONFIGURE_WITH=		debug

JMA_DESC=			JMA archive decompression support
JMA_CONFIGURE_WITH=		jma-decomp

NETPLAY_DESC=			Network support
NETPLAY_CONFIGURE_WITH=		netplay

OPENGL_CONFIGURE_WITH=		opengl
OPENGL_USE=			GL=gl,glu

XRANDR_CONFIGURE_WITH=		xrandr
XRANDR_USE=			XORG=xrandr

XVIDEO_CONFIGURE_WITH=		xv
XVIDEO_USE=			XORG=xv

ALSA_CONFIGURE_WITH=		alsa
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_USES=			compiler:c++11-lang

PORTAUDIO_CONFIGURE_WITH=	portaudio
PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio

PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

PLIST_FILES=	bin/snes9x-gtk \
		share/pixmaps/snes9x.svg \
		share/applications/snes9x.desktop

.include <bsd.port.pre.mk>

.if exists(/usr/lib/libusbhid.a)
CONFIGURE_ARGS+=	--with-joystick
.else
CONFIGURE_ARGS+=	--without-joystick
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl|sdl2|g' -e 's|-ldl||g' \
		${WRKSRC}/configure.ac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/snes9x.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.post.mk>
