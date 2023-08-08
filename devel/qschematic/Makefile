PORTNAME=	qschematic
DISTVERSION=	1.4.0
CATEGORIES=	devel

MAINTAINER=	jbo@insane.engineer
COMMENT=	Qt/C++ library providing widgets for drawing diagrams
WWW=		https://github.com/simulton/qschematic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libgpds.so:devel/gpds

USES=		cmake compiler:c++17-lang qt:5
USE_QT=		buildtools:build core gui qmake:build widgets

USE_GITHUB=	yes
GH_ACCOUNT=	simulton
GH_PROJECT=	QSchematic

CMAKE_OFF=	QSCHEMATIC_BUILD_DEMO QSCHEMATIC_DEPENDENCY_GPDS_DOWNLOAD
CMAKE_ARGS=	-DQSCHEMATIC_DEPENDENCY_GPDS_TARGET:STRING="gpds::gpds-shared"

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
