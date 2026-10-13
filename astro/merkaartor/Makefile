PORTNAME=	merkaartor
PORTVERSION=	0.20.0
PORTREVISION=	1
CATEGORIES=	astro

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Openstreetmap mapping program
WWW=		http://merkaartor.be/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libexiv2.so:graphics/exiv2 \
		libprotobuf.so:devel/protobuf \
		libproxy.so:net/libproxy

USES=		cmake compiler:c++17-lang gnome pkgconfig qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap
USE_LDCONFIG=	yes

USE_QT=		5compat base networkauth svg webengine \
		imageformats:run \
		tools:build

CMAKE_ON=	LIBPROXY WEBENGINE

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

# ZBAR_DESC=	Read barcodes from walking papers (BROKEN)
# ZBAR_CMAKE_ON=	ZBAR
# ZBAR_LIB_DEPENDS=	libzbar.so:graphics/zbar
# # graphics/zbar needs to be built with Qt6 support
# ZBAR_BROKEN=	Does not build with option ZBAR selected

.include <bsd.port.mk>
