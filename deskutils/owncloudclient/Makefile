# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	owncloudclient
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://download.owncloud.com/desktop/stable/

MAINTAINER=	yonas@fizk.net
COMMENT=	OwnCloud Desktop Syncing Client

LICENSE=	GPLv2

LIB_DEPENDS=	libinotify.so:${PORTSDIR}/devel/libinotify \
		libqt5keychain.so:${PORTSDIR}/security/qtkeychain-qt5

USES=		cmake:outsource compiler:c++11-lib gmake iconv pkgconfig tar:xz
USE_QT5=	buildtools_build concurrent core dbus gui linguist_build network \
		qmake_build webkit xml
USE_OPENSSL=	yes
USE_SQLITE=	3
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=OFF \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_STACK_PROTECTOR:BOOL=OFF
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCS_USE=		tex=dvipsk:build,latex:build
DOCS_CMAKE_ON=		-DWITH_DOC:BOOL=ON

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1000015
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
