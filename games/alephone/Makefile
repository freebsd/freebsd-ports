# Created by: Michael Alyn Miller <malyn@strangeGizmo.com>
# $FreeBSD$

PORTNAME=	alephone
PORTVERSION=	20120514
PORTREVISION=	7
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

MAD_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad
MAD_CONFIGURE_ENABLE=	mad

OGG_LIB_DEPENDS=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
OGG_CONFIGURE_ENABLE=	vorbis

SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ENABLE=	speex

SMPEG_LIB_DEPENDS=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg
SMPEG_CONFIGURE_ENABLE=	smpeg

TTF_USE=	SDL=ttf
TTF_CONFIGURE_ENABLE=	ttf

ZZIP_LIB_DEPENDS=	libzzip.so:${PORTSDIR}/devel/zziplib
ZZIP_CONFIGURE_ENABLE=	zzip

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
