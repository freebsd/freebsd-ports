PORTNAME=	minizip-ng
DISTVERSION=	4.0.10
CATEGORIES=	archivers

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Fork of the popular minizip found in the zlib distribution
WWW=		https://github.com/zlib-ng/minizip-ng

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libz-ng.so:archivers/zlib-ng \
		libzstd.so:archivers/zstd

USES=		cmake:testing iconv pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	zlib-ng
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=${LOCALBASE}/include/ \
		-DMZ_LIB_SUFFIX=-ng
CMAKE_ON=	BUILD_SHARED_LIBS CMAKE_DISABLE_FIND_PACKAGE_ZLIB
CMAKE_TESTING_ON=	MZ_BUILD_TEST MZ_BUILD_UNIT_TEST

PLIST_SUB+=	VERSION="${DISTVERSION}"

post-install:
	${INSTALL_DATA} ${FILESDIR}/mz_compat.h \
		${STAGEDIR}${PREFIX}/include/minizip-ng/

.include <bsd.port.mk>
