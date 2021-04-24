PORTNAME=	copyq
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.0
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt5 based clipboard manager

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake:devel/kf5-extra-cmake-modules

LIB_DEPENDS=	libKF5Notifications.so.5:devel/kf5-knotifications \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lang qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	hluk
GH_PROJECT=	CopyQ

USE_KDE=	notifications
USE_LDCONFIG=	yes
USE_QT=		core declarative gui network script svg widgets x11extras \
		imageformats_run buildtools_build linguisttools_build \
		qmake_build wayland
USE_XORG=	x11 xtst

LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=		PLUGINS WEBKIT
OPTIONS_DEFAULT=	PLUGINS WEBKIT
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

WEBKIT_IMPLIES=		PLUGINS
WEBKIT_USE=		qt=webkit
WEBKIT_CMAKE_BOOL=	WITH_WEBKIT

.include <bsd.port.mk>
