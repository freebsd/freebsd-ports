PORTNAME=	alephone
DISTVERSION=	20230119
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	https://github.com/Aleph-One-Marathon/${PORTNAME}/releases/download/release-${DISTVERSION}/
DISTNAME=	AlephOne-${DISTVERSION}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Open source version of Bungies Marathon game
WWW=		http://source.bungie.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libavcodec.so:multimedia/ffmpeg \
		libsndfile.so:audio/libsndfile \

USES=		compiler:c++17-lang gmake localbase openal \
		pkgconfig shared-mime-info sdl gl tar:bzip2
USE_SDL=	sdl2 image2 net2 ttf2
USE_GL=		gl glu

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	*
DATADIR=	${PREFIX}/share/AlephOne

CONFIGURE_ARGS=	--without-alsa --without-mad --without-miniupnpc \
		--without-smpeg --without-vorbis

OPTIONS_DEFINE=	CURL DOCS PNG SPEEX ZZIP
OPTIONS_DEFAULT=CURL DOCS PNG SPEEX ZZIP

ZZIP_DESC=	Enable zziplib support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
SPEEX_CONFIGURE_WITH=	speex

ZZIP_LIB_DEPENDS=	libzzip.so:devel/zziplib
ZZIP_CONFIGURE_WITH=	zzip

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} README.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
