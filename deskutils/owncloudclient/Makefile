# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	owncloudclient
PORTVERSION=	2.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	yonas@fizk.net
COMMENT=	OwnCloud Desktop Syncing Client

LICENSE=	GPLv2

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain-qt5

USES=		cmake:outsource compiler:c++11-lib gmake iconv \
		localbase:ldflags pkgconfig sqlite ssl
USE_QT5=	buildtools_build concurrent core dbus gui linguist_build network \
		qmake_build sql webkit widgets xml
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=OFF \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_STACK_PROTECTOR:BOOL=OFF
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	owncloud
GH_PROJECT=	client

OPTIONS_DEFINE=		DEBUG DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_USE=		tex=dvipsk:build,latex:build
DOCS_CMAKE_ON=		-DWITH_DOC:BOOL=ON

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE:STRING=Debug

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
WITH_OPENSSL_PORT=	yes

# CMake 3.3.x will use $PATH when looking for headers and libraries by default,
# and OpenSSL from base will end up being used. Make sure ${LOCALBASE} is
# preferred over $PATH.
CMAKE_ARGS+=		-DCMAKE_PREFIX_PATH=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@(cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample)

.include <bsd.port.mk>
