PORTNAME=	alephone
DISTVERSION=	20250829
CATEGORIES=	games
MASTER_SITES=	https://github.com/Aleph-One-Marathon/${PORTNAME}/releases/download/release-${DISTVERSION}/
DISTNAME=	AlephOne-${DISTVERSION}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Open source version of Bungies Marathon game
WWW=		http://source.bungie.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	asio>0:net/asio
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libsndfile.so:audio/libsndfile \
		libvorbisenc.so:audio/libvorbis \
		libyuv.so:graphics/libyuv

USES=		compiler:c++17-lang gl gmake localbase openal pkgconfig sdl \
		shared-mime-info tar:bzip2
USE_GL=		gl glu
USE_SDL=	image2 net2 sdl2 ttf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-miniupnpc \
		--without-vorbis

LDFLAGS+=	-lpthread

DATADIR=	${PREFIX}/share/AlephOne
PORTDOCS=	*

OPTIONS_DEFINE=		CURL DOCS PNG ZZIP
OPTIONS_DEFAULT=	CURL DOCS PNG ZZIP

ZZIP_DESC=	Enable zziplib support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	png

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
