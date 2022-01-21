PORTNAME=	gcompris-qt
DISTVERSION=	2.1
CATEGORIES=	games education kde
MASTER_SITES=	http://gcompris.net/download/qt/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational games and activities for kids ages 2 to 10

LICENSE=	AGPLv3 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libBox2D.so:x11-toolkits/qml-box2d

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	doctools_build ecm_build
USE_QT=		core declarative graphicaleffects gui multimedia network quickcontrols \
		sensors svg widgets \
		buildtools_build linguisttools_build qmake_build testlib_build

CMAKE_ARGS=	-DQML_BOX2D_LIBRARY=${QT_QMLDIR}/Box2D.2.0

.include <bsd.port.mk>
