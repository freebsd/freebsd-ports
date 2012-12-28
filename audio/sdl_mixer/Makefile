# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.12
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/
DISTNAME=	SDL_mixer-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A sample multi-channel audio mixer library

LICENSE=	ZLIB

USE_AUTOTOOLS=	libtool
USE_SDL=	sdl
USE_PKGCONFIG=	yes
USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		MIKMOD SMPEG FLAC VORBIS TIMIDITYPLUS
OPTIONS_DEFAULT=	MIKMOD SMPEG FLAC VORBIS

MIKMOD_DESC=	Enable MOD music via libMikMod
SMPEG_DESC=	Enable MP3 music via SMPEG
FLAC_DESC=	Enable FLAC encoding support via flac
VORBIS_DESC=	Enable Ogg Vorbis music
TIMIDITYPLUS_DESC=	Use Timidity++ instead of Timidity (soundfont)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMIKMOD}
LIB_DEPENDS+=	mikmod:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=	--enable-music-mod
.else
CONFIGURE_ARGS+=	--disable-music-mod
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=	--enable-music-flac
.else
CONFIGURE_ARGS+=	--disable-music-flac
.endif

.if ${PORT_OPTIONS:MSMPEG}
LIB_DEPENDS+=	smpeg:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=	--enable-music-mp3
.else
CONFIGURE_ARGS+=	--disable-music-mp3
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=		vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-music-ogg
.else
CONFIGURE_ARGS+=	--disable-music-ogg
.endif

.if ${PORT_OPTIONS:MTIMIDITYPLUS}
RUN_DEPENDS+=	${LOCALBASE}/share/timidity/timidity.cfg-eawpats:${PORTSDIR}/audio/eawpats
CONFIG_FILE=	${LOCALBASE}/share/timidity/timidity.cfg-eawpats
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/timidity/timidity.cfg:${PORTSDIR}/audio/timidity
CONFIG_FILE=	${LOCALBASE}/lib/timidity/timidity.cfg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CONFIG_FILE%%|${CONFIG_FILE}|g' \
		${WRKSRC}/timidity/config.h

.include <bsd.port.post.mk>
