# Created by: Michael Alyn Miller <malyn@strangeGizmo.com>

PORTNAME=	alephone
DISTVERSION=	20190331
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Open source version of Bungies Marathon game

LICENSE=	GPLv3

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libboost_filesystem.so:devel/boost-libs

USES=		autoreconf compiler:c++11-lang gmake localbase \
		pkgconfig shared-mime-info sdl gl tar:bzip2

USE_SDL=	sdl2 image2 net2 ttf2
USE_GL=		gl glu

USE_GITHUB=	yes
GH_ACCOUNT=	Aleph-One-Marathon
GH_TAGNAME=	release-20190331

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa

PORTDOCS=	*

DATADIR=	${PREFIX}/share/AlephOne

OPTIONS_DEFINE=	MAD FFMPEG OGG SPEEX ZZIP PNG CURL SNDFILE DOCS
OPTIONS_DEFAULT=MAD FFMPEG OGG SPEEX ZZIP PNG CURL SNDFILE

FFMPEG_DESC=	Use ffmpeg for film export and playback
ZZIP_DESC=	Enable zziplib support

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_WITH=	mad
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg
OGG_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
OGG_CONFIGURE_WITH=	vorbis
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
SPEEX_CONFIGURE_WITH=	speex
ZZIP_LIB_DEPENDS=	libzzip.so:devel/zziplib
ZZIP_CONFIGURE_WITH=	zzip
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_WITH=	sndfile

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
