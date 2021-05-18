PORTNAME=	soundtracker
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pattern-oriented music editor

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile
RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils gettext gmake gnome pkgconfig shebangfix tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 pango
USE_XORG=	x11

SHEBANG_FILES=	soundtracker_convert_config

CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl2-config

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	JACK OSS PULSEAUDIO SDL
OPTIONS_DEFAULT=	JACK OSS PULSEAUDIO SDL

BACKEND_DESC=			Audio backends:

JACK_CONFIGURE_ENABLE=		jack
JACK_LIB_DEPENDS=		libjack.so:audio/jack

OSS_CONFIGURE_ENABLE=		oss

PULSEAUDIO_CONFIGURE_ENABLE=	pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

SDL_CONFIGURE_ENABLE=		sdl
SDL_USES=			sdl
SDL_USE=			SDL=sdl2

.include <bsd.port.mk>
