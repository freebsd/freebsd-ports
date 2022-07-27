PORTNAME=	qschematic
PORTVERSION=	1.3.1
CATEGORIES=	devel

MAINTAINER=	jbo@insane.engineer
COMMENT=	Qt/C++ library providing widgets for drawing diagrams

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libgpds.so:devel/gpds

USES=		cmake compiler:c++17-lang qt:5
USE_QT=		buildtools_build core gui qmake_build widgets

USE_GITHUB=	yes
GH_ACCOUNT=	simulton
GH_PROJECT=	QSchematic

CMAKE_OFF=	QSCHEMATIC_BUILD_DEMO QSCHEMATIC_DEPENDENCY_GPDS_DOWNLOAD
CMAKE_ARGS=	-DQSCHEMATIC_DEPENDENCY_GPDS_TARGET:STRING="gpds::gpds-shared"

.include <bsd.port.mk>
