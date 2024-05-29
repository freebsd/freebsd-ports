PORTNAME=	minizip-ng
DISTVERSION=	4.0.5
CATEGORIES=	archivers

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Fork of the popular minizip found in the zlib distribution
WWW=		https://github.com/zlib-ng/minizip-ng

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake:testing iconv pathfix pkgconfig ssl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zlib-ng

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=${LOCALBASE}/include/ \
		-DMZ_LIB_SUFFIX=-ng
CMAKE_TESTING_ON=	MZ_BUILD_TEST MZ_BUILD_UNIT_TEST

.include <bsd.port.mk>
