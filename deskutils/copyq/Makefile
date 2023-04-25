PORTNAME=	copyq
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.0
PORTREVISION=	2
CATEGORIES=	deskutils
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Qt${FLAVOR:S/qt//} based clipboard manager
WWW=		https://github.com/hluk/CopyQ

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

qt5_CONFLICTS_INSTALL=	copyq-qt6
qt6_CONFLICTS_INSTALL=	copyq-qt5

USES=		cmake compiler:c++17-lang gl kde:5 qt:${FLAVOR:S/qt//} xorg
USE_GITHUB=	yes
GH_ACCOUNT=	hluk
GH_PROJECT=	CopyQ
USE_GL=		gl
USE_KDE=	notifications # needed WITH_QT6, Extra CMake Modules (ECM)
_USE_QT5=	core dbus declarative gui network svg wayland widgets x11extras \
		xml buildtools:build qmake:build
_USE_QT6=	base declarative svg wayland translations:build
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}
USE_XORG=	ice sm x11 xext xfixes xtst

_QT6_CMAKE_ARGS=	-DQtWaylandScanner_EXECUTABLE=${PREFIX}/libexec/qt6/qtwaylandscanner \
			-DWITH_QT6:BOOL=TRUE
CMAKE_ARGS=		${_QT${FLAVOR:S/qt//}_CMAKE_ARGS}

PORTSCOUT=	limit:^d\.d\.

OPTIONS_DEFINE=		PLUGINS
OPTIONS_DEFAULT=	PLUGINS
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

.include <bsd.port.mk>
