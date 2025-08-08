PORTNAME=	redisdesktopmanager
PORTVERSION=	2022.5
CATEGORIES=	databases

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Redis DB management tool
WWW=		https://github.com/RedisInsight/RedisDesktopManager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	RedisDesktopManager is no longer maintained upstream as the project has been replaced by RedisInsight
EXPIRATION_DATE=2025-09-08

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		liblz4.so:archivers/liblz4 \
		libpython${PYTHON_VER}${PYTHON_ABIVER}.so:lang/python${PYTHON_SUFFIX} \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd \
		libssh2.so:security/libssh2

USES=		compiler:c++0x dos2unix gettext-runtime gl kde:5 python:build \
		qmake qt:5
DOS2UNIX_FILES=	3rdparty/3rdparty.pri
USE_GITHUB=	yes
GH_TUPLE=	RedisInsight:RedisDesktopManager:${PORTVERSION}:DEFAULT/RedisDesktopManager-${PORTVERSION} \
		benlau:asyncfuture:5ca0304:asyncfuture/3rdparty/qredisclient/3rdparty/asyncfuture \
		eranpeer:FakeIt:80a446b:FakeIt/3rdparty/fakeit \
		uglide:pyotherside:c1a8cc0:pyotherside/3rdparty/pyotherside \
		uglide:qredisclient:901b005:qredisclient/3rdparty/qredisclient \
		redis:hiredis:b731283:hiredis/3rdparty/qredisclient/3rdparty/hiredis \
		simdjson:simdjson:3bd8b0b:simdjson/3rdparty/simdjson
USE_GL=		gl
USE_QT=		charts concurrent core declarative gui network quickcontrols \
		svg widgets buildtools:build qmake:build

QMAKE_ARGS+=	SYSTEM_BROTLI=1 SYSTEM_LZ4=1 SYSTEM_SNAPPY=1 SYSTEM_ZSTD=1 \
		VERSION=${PORTVERSION}

CXXFLAGS_powerpc64=	-mpower8-vector

BINARY_ALIAS=	python3-config=${PYTHON_CMD}-config python3=${PYTHON_CMD}
DESKTOP_ENTRIES=	"GUI for Redis" \
			"GUI for Redis" \
			"resp" \
			"resp" \
			"Development;" \
			""

BUILD_WRKSRC=		${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=		${WRKSRC}/bin/linux/release

PLIST_FILES=	bin/resp \
		share/pixmaps/resp.png

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/pixmaps
	cd ${INSTALL_WRKSRC} ; \
	${STRIP_CMD} resp ; \
	${INSTALL_PROGRAM} resp ${STAGEDIR}${PREFIX}/bin/resp
	${INSTALL_DATA} ${BUILD_WRKSRC}/resources/images/resp.png ${STAGEDIR}${PREFIX}/share/pixmaps/resp.png

.include <bsd.port.mk>
