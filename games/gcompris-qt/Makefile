PORTNAME=	gcompris-qt
DISTVERSION=	4.2
CATEGORIES=	games education kde
MASTER_SITES=	https://gcompris.net/download/qt/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational games and activities for kids ages 2 to 10
WWW=		https://gcompris.net/

LICENSE=		AGPLv3 GPLv3
LICENSE_COMB=		multi
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

# libqmlbox2d.so is a QML plugin...don't use LIB_DEPENDS
BUILD_DEPENDS=	${_BOX2D_PATH}/libqmlbox2d.so:x11-toolkits/qml-box2d@qt5
RUN_DEPENDS=	${_BOX2D_PATH}/libqmlbox2d.so:x11-toolkits/qml-box2d@qt5

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	doctools:build ecm:build
USE_QT=		charts core declarative graphicaleffects gui multimedia \
		network quickcontrols2 sensors svg widgets \
		buildtools:build linguisttools:build qmake:build testlib:build \
		imageformats:run

CMAKE_ARGS=	-DQML_BOX2D_LIBRARY=${_BOX2D_PATH}

_BOX2D_PATH=	${QT_QMLDIR}/Box2D

post-patch:
	${REINPLACE_CMD} -e 's|Box2D\.2\.0|Box2D|g' \
		${WRKSRC}/src/core/ApplicationInfo.cpp

.include <bsd.port.mk>
