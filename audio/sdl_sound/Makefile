# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	sdl_sound
PORTVERSION=	1.0.3
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	http://www.icculus.org/SDL_sound/downloads/
DISTNAME=	SDL_sound-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SDL audio library and player for some popular sound file formats

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool localbase sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		FLAC MIKMOD MIDI MODPLUG PHYSFS SMPEG SPEEX VORBIS
OPTIONS_DEFAULT=	FLAC MIKMOD MIDI MODPLUG PHYSFS SMPEG SPEEX VORBIS

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libogg.so:audio/libogg
FLAC_CONFIGURE_ENABLE=	flac

MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MIKMOD_CONFIGURE_ENABLE=mikmod

MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=modplug

PHYSFS_DESC=		PhysicsFS support
PHYSFS_LIB_DEPENDS=	libphysfs.so:devel/physfs
PHYSFS_CONFIGURE_ENABLE=physfs

SMPEG_DESC=		MP3 audio format
SMPEG_BROKEN_OFF=	Built-in MP3 support is currently broken, consider enabling the SMPEG option to use that library instead
SMPEG_LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg
SMPEG_CPPFLAGS=		-isystem ${LOCALBASE}/include/smpeg
SMPEG_CONFIGURE_ON=	--disable-mpglib
SMPEG_CONFIGURE_OFF=	--disable-smpeg

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libogg.so:audio/libogg
SPEEX_CONFIGURE_ENABLE=	speex

MIDI_DESC=		Software MIDI music
MIDI_RUN_DEPENDS=	timidity>=0:audio/timidity
MIDI_BUILD_DEPENDS=	timidity>=0:audio/timidity
MIDI_CONFIGURE_ENABLE=	midi

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CONFIGURE_ENABLE=ogg

pre-configure-MIDI-on:
	@if ! [ -e "${LOCALBASE}/lib/timidity/goemon.cfg" ]; then \
		${ECHO_CMD} 'MIDI support requires audio/timidity port to be built with GOEMON option enabled, which is not the case'; \
		${ECHO_CMD} 'Please, run `make -C ${PORTSDIR}/audio/timidity config` and enable GOEMON option to continue'; \
		${FALSE}; \
	fi

post-patch:
	@${REINPLACE_CMD} 's|timidity.cfg|${PREFIX}/share/timidity/&|' \
		${WRKSRC}/decoders/timidity/options.h
	@${REINPLACE_CMD} 's|__EXPORT__||' \
		${WRKSRC}/playsound/physfsrwops.h

.include <bsd.port.mk>
