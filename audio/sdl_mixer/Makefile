# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.12
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library

LICENSE=	ZLIB

USES=		gmake libtool:oldver pathfix pkgconfig
USE_SDL=	sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		SMPEG FLAC VORBIS TIMIDITYPLUS
OPTIONS_DEFAULT=	SMPEG FLAC VORBIS MIKMOD
OPTIONS_RADIO=		MOD
OPTIONS_RADIO_MOD=	MIKMOD MODPLUG

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTIMIDITYPLUS}
RUN_DEPENDS+=	${LOCALBASE}/share/timidity/timidity.cfg-eawpats:${PORTSDIR}/audio/eawpats
CONFIG_FILE=	${LOCALBASE}/share/timidity/timidity.cfg-eawpats
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/timidity/timidity.cfg:${PORTSDIR}/audio/timidity
CONFIG_FILE=	${LOCALBASE}/lib/timidity/timidity.cfg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\($$(prefix)/libdata/pkgconfig\)|$$(DESTDIR)\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%CONFIG_FILE%%|${CONFIG_FILE}|g' \
		${WRKSRC}/timidity/config.h
	@${REINPLACE_CMD} -e 's|"modplug.h"|"libmodplug/modplug.h"|' \
		${WRKSRC}/music_modplug.h

.include <bsd.port.mk>
