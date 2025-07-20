PORTNAME=	gcompris-qt
DISTVERSION=	25.1.1
CATEGORIES=	games education kde
MASTER_SITES=	https://gcompris.net/download/qt/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational games and activities for kids ages 2 to 10
WWW=		https://gcompris.net/

LICENSE=		AGPLv3 GPLv3
LICENSE_COMB=		multi
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

# libqmlbox2d.so is a QML plugin...don't use LIB_DEPENDS
BUILD_DEPENDS=	${_BOX2D_PATH}/libqmlbox2d.so:x11-toolkits/qml-box2d
RUN_DEPENDS=	${_BOX2D_PATH}/libqmlbox2d.so:x11-toolkits/qml-box2d

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl # GLX
USE_KDE=	doctools:build ecm:build
USE_QT=		base charts declarative multimedia sensors svg \
		tools:build imageformats:run

CMAKE_ARGS=	-DQML_BOX2D_LIBRARY=${_BOX2D_PATH}

OPTIONS_DEFINE=		WAYLAND
OPTIONS_DEFAULT=	WAYLAND

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_USE=		QT=wayland
WAYLAND_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WaylandClient

_BOX2D_PATH=	${QT_QMLDIR}/Box2D

post-patch:
	${REINPLACE_CMD} -e 's|Box2D\.2\.0|Box2D|g' \
		${WRKSRC}/src/core/ApplicationInfo.cpp

.include <bsd.port.mk>
