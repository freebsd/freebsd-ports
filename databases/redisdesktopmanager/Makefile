# $FreeBSD$

PORTNAME=	redisdesktopmanager
PORTVERSION=	2021.2
CATEGORIES=	databases

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Redis DB management tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libpython${PYTHON_VER}${PYTHON_ABIVER}.so:lang/python${PYTHON_SUFFIX} \
		libssh2.so:security/libssh2

USES=		compiler:c++0x dos2unix gettext-runtime gl kde:5 python:build \
		qmake qt:5

USE_GL=		gl
USE_GITHUB=	yes

DOS2UNIX_FILES=		3rdparty/3rdparty.pri
BUILD_WRKSRC=		${WRKSRC}/src
CONFIGURE_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=		${WRKSRC}/bin/linux/release
PLIST_FILES=		bin/rdm \
			share/pixmaps/rdm.png
DESKTOP_ENTRIES=	"Redis Desktop Manager" \
			"Redis Desktop Manager" \
			"rdm" \
			"rdm" \
			"Development;" \
			""
GH_TUPLE=		uglide:RedisDesktopManager:${PORTVERSION}:DEFAULT/RedisDesktopManager-${PORTVERSION} \
			benlau:asyncfuture:5ca0304:asyncfuture/3rdparty/qredisclient/3rdparty/asyncfuture \
			uglide:qredisclient:103096d:qredisclient/3rdparty/qredisclient \
			sijk:qt-unix-signals:d6a1d12:qtunixsignals/3rdparty/qt-unix-signals \
			uglide:qsshclient:6fa7fb7:qsshclient/3rdparty/qredisclient/3rdparty/qsshclient \
			uglide:pyotherside:c1a8cc0:pyotherside/3rdparty/pyotherside \
			redis:hiredis:6850306:hiredis/3rdparty/qredisclient/3rdparty/hiredis
USE_QT=			charts concurrent core declarative gui network svg \
			widgets buildtools_build qmake_build

QMAKE_ARGS+=	SYSTEM_LZ4=1 VERSION=${PORTVERSION}

BINARY_ALIAS=	python3-config=${PYTHON_CMD}-config python3=${PYTHON_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/share/pixmaps
	cd ${INSTALL_WRKSRC} ; \
	${STRIP_CMD} rdm ; \
	${INSTALL_PROGRAM} rdm ${STAGEDIR}${PREFIX}/bin/rdm
	${INSTALL_DATA} ${BUILD_WRKSRC}/resources/images/rdm.png ${STAGEDIR}${PREFIX}/share/pixmaps/rdm.png

.include <bsd.port.mk>
