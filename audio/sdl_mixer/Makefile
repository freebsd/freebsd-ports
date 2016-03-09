# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.12
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library

LICENSE=	ZLIB

USES=		gmake libtool pathfix pkgconfig
USE_SDL=	sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		SMPEG FLAC TIMIDITYPLUS
OPTIONS_DEFAULT=	SMPEG FLAC MIKMOD
OPTIONS_RADIO=		MOD OGG
OPTIONS_RADIO_MOD=	MIKMOD MODPLUG
OPTIONS_RADIO_OGG=	VORBIS TREMOR

.if defined(MACHINE_CPU) && ${MACHINE_CPU:Msoftfp}
OPTIONS_DEFAULT+=	TREMOR
.else
OPTIONS_DEFAULT+=	VORBIS
.endif

MIKMOD_DESC=	Enable MOD music via libMikMod
MODPLUG_DESC=	Enable MOD music via libModPlug
SMPEG_DESC=	Enable MP3 music via SMPEG
FLAC_DESC=	Enable FLAC encoding support via flac
VORBIS_DESC=	Enable Ogg Vorbis music
TIMIDITYPLUS_DESC=	Use Timidity++ instead of Timidity (soundfont)

MIKMOD_LIB_DEPENDS=		libmikmod.so:${PORTSDIR}/audio/libmikmod
MIKMOD_CONFIGURE_ENABLE=	music-mod

MODPLUG_LIB_DEPENDS=		libmodplug.so:${PORTSDIR}/audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	music-mod-modplug

FLAC_LIB_DEPENDS=		libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_ENABLE=		music-flac

SMPEG_LIB_DEPENDS=		libsmpeg.so:${PORTSDIR}/multimedia/smpeg
SMPEG_CONFIGURE_ENABLE=		music-mp3

VORBIS_LIB_DEPENDS=		libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	music-ogg

TIMIDITYPLUS_RUN_DEPENDS=	${LOCALBASE}/share/timidity/timidity.cfg-eawpats:${PORTSDIR}/audio/eawpats
TIMIDITYPLUS_VARS=		CONFIG_FILE=${LOCALBASE}/share/timidity/timidity.cfg-eawpats

TIMIDITYPLUS_RUN_DEPENDS_OFF=	${LOCALBASE}/lib/timidity/timidity.cfg:${PORTSDIR}/audio/timidity
TIMIDITYPLUS_VARS_OFF=		CONFIG_FILE=${LOCALBASE}/lib/timidity/timidity.cfg

TREMOR_LIB_DEPENDS=		libvorbisidec.so:${PORTSDIR}/audio/libtremor
TREMOR_CONFIGURE_ENABLE=	music-ogg music-ogg-tremor

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(prefix)/libdata/pkgconfig\)|$$(DESTDIR)\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%CONFIG_FILE%%|${CONFIG_FILE}|g' \
		${WRKSRC}/timidity/config.h
	@${REINPLACE_CMD} -e 's|"modplug.h"|"libmodplug/modplug.h"|' \
		${WRKSRC}/music_modplug.h

.include <bsd.port.mk>
