PORTNAME=	simage
DISTVERSION=	1.8.4
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/coin3d/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	florianmarx@free.fr
COMMENT=	Library with image format loaders and front-ends
WWW=		https://github.com/coin3d/simage/

LICENSE=		ISC MPEG2ENC
LICENSE_COMB=		multi
LICENSE_NAME_ISC=	ISC License
LICENSE_NAME_MPEG2ENC=	mpeg2enc license
LICENSE_FILE_ISC=	${WRKSRC}/LICENSE
LICENSE_FILE_MPEG2ENC=	${WRKSRC}/LICENSE.mpeg2enc
LICENSE_PERMS_ISC=	dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_PERMS_MPEG2ENC=	no-dist-sell no-pkg-sell

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libFLAC.so:audio/flac \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libzstd.so:archivers/zstd \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libjasper.so:graphics/jasper

USES=		cmake jpeg localbase:ldflags
USE_LDCONFIG=	yes

CMAKE_ON=	SIMAGE_MPEG2ENC_SUPPORT

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	VERSION="${DISTVERSION}"

.include <bsd.port.mk>
