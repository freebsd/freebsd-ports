# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	owncloudclient
DISTVERSION=	2.6.0
DISTVERSIONSUFFIX=	.13018
CATEGORIES=	deskutils
MASTER_SITES=	https://download.owncloud.com/desktop/stable/
# owncloudclient-2.6.0.13018.tar.xz

MAINTAINER=	yonas@fizk.net
COMMENT=	OwnCloud Desktop Syncing Client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libqt5keychain.so:security/qtkeychain

USES=		cmake:noninja compiler:c++11-lib gmake iconv kde:5 \
		localbase:ldflags pkgconfig qt:5 sqlite tar:xz
USE_QT=		buildtools_build concurrent core dbus gui linguist_build network \
		qmake_build sql webkit widgets xml
USE_KDE=	completion config coreaddons jobwidgets kio service widgetsaddons
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=OFF \
		-DCMAKE_INSTALL_MANDIR:STRING=man \
		-DWITH_DOC:BOOL=OFF \
		-DWITH_STACK_PROTECTOR:BOOL=OFF
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DEBUG

DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE:STRING=Debug

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e \
		's|.lst |.lst.sample |' ${WRKSRC}/CMakeLists.txt

pre-configure:
	@cd ${WRKSRC} && ${CP} -f sync-exclude.lst sync-exclude.lst.sample

.include <bsd.port.mk>
