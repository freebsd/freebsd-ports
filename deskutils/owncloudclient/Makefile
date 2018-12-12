# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	owncloudclient
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	yonas@fizk.net
COMMENT=	OwnCloud Desktop Syncing Client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake:outsource,noninja compiler:c++11-lib gmake iconv kde:5 \
		localbase:ldflags pkgconfig qt:5 sqlite
USE_QT=		buildtools_build concurrent core dbus gui linguist_build network \
		qmake_build sql webkit widgets xml
USE_KDE=	completion config coreaddons jobwidgets kio service widgetsaddons
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=OFF \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_STACK_PROTECTOR:BOOL=OFF
USE_GITHUB=	yes
GH_ACCOUNT=	owncloud
GH_PROJECT=	client
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DEBUG DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_USE=		tex=dvipsk:build,latex:build
DOCS_CMAKE_ON=		-DWITH_DOC:BOOL=ON

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE:STRING=Debug

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample

.include <bsd.port.mk>
