PORTNAME=	copyq
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.0
PORTREVISION=	3
CATEGORIES=	deskutils
PKGNAMESUFFIX=	-${FLAVOR}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	79d33dd337deeb357ce92c3d1e2b5b56b6f2c97d.patch:-p1 # Fix build with Qt 6.5.x
PATCHFILES+=	8ae296bed45a7679712aff0cb2e2d0508330ad37.patch:-p1 # Fix cmake warnings

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Qt${FLAVOR:S/qt//} based clipboard manager
WWW=		https://github.com/hluk/CopyQ

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS=		qt5 qt6
FLAVOR?=		qt5
qt5_CONFLICTS_INSTALL=	copyq-qt6
qt6_CONFLICTS_INSTALL=	copyq-qt5

USES=		cmake compiler:c++17-lang gl kde:5 pkgconfig \
		qt:${FLAVOR:S/qt//} xorg
USE_GITHUB=	yes
GH_ACCOUNT=	hluk
GH_PROJECT=	CopyQ
USE_GL=		gl
_USE_KDE_qt5=	ecm:build notifications
_USE_KDE_qt6=	ecm:build
USE_KDE=	${_USE_KDE_${FLAVOR}}
_USE_QT5=	core dbus declarative gui network svg wayland widgets x11extras \
		xml buildtools:build qmake:build
_USE_QT6=	base declarative svg wayland translations:build
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}
USE_XORG=	ice sm x11 xext xfixes xtst

_QT6_CMAKE_ARGS=	-DWITH_QT6:BOOL=TRUE
CMAKE_ARGS=		${_QT${FLAVOR:S/qt//}_CMAKE_ARGS}

PORTSCOUT=	limit:^d\.d\.

OPTIONS_DEFINE=		PLUGINS
OPTIONS_DEFAULT=	PLUGINS
OPTIONS_SUB=		yes

PLUGINS_CMAKE_BOOL=	WITH_PLUGINS

.include <bsd.port.mk>
