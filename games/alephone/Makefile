# Created by: Michael Alyn Miller <malyn@strangeGizmo.com>
# $FreeBSD$

PORTNAME=	alephone
PORTVERSION=	20120514
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/marathon/Aleph%20One/2012-05-14
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	The open source version of Bungie's Marathon game

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs

USES=		gmake pkgconfig tar:bzip2
USE_SDL=	image net sdl sound
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-alsa --disable-sndfile

DATADIR=	${PREFIX}/share/AlephOne

OPTIONS_DEFINE=	MAD OGG SPEEX SMPEG TTF ZZIP DOCS
SMPEG_DESC=	Use SMPEG for movie playback
TTF_DESC=	Enable SDL_ttf font rendering
ZZIP_DESC=	Enable zziplib support

OPTIONS_DEFAULT=	MAD OGG SPEEX SMPEG TTF ZZIP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAD}
LIB_DEPEND+=	libmad.so:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPEND+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	libspeex.so:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if ${PORT_OPTIONS:MSMPEG}
LIB_DEPENDS+=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg
.else
CONFIGURE_ARGS+=--disable-smpeg
.endif

.if ${PORT_OPTIONS:MTTF}
USE_SDL+=	ttf
.else
CONFIGURE_ARGS+=--disable-ttf
.endif

.if ${PORT_OPTIONS:MZZIP}
LIB_DEPENDS+=	libzzip.so:${PORTSDIR}/devel/zziplib
.else
CONFIGURE_ARGS+=--disable-zzip
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
