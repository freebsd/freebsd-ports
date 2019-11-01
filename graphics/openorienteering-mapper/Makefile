# Created by: Nikolay Korotkiy <sikmir@gmail.com>
# $FreeBSD$

PORTNAME=	openorienteering-mapper
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics geography

MAINTAINER=	sikmir@gmail.com
COMMENT=	Map drawing program from OpenOrienteering

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolyclipping.so:graphics/polyclipping \
		libproj.so:graphics/proj

USES=		cmake:noninja compiler:c++14-lang \
		desktop-file-utils gmake qt:5 shared-mime-info
USE_QT=		buildtools_build help qmake_build core gui \
		network printsupport widgets
USE_GITHUB=	yes
GH_ACCOUNT=	OpenOrienteering
GH_PROJECT=	mapper

CMAKE_ARGS+=	-DLICENSING_PROVIDER=freebsd \
		-DMapper_PACKAGE_NAME=${PORTNAME} \
		-Wno-dev

OPTIONS_DEFINE=	DOCS EXAMPLES GDAL NLS POSITIONING TEST TIFF
OPTIONS_DEFAULT=	DOCS EXAMPLES GDAL NLS TIFF
OPTIONS_SUB=	yes
DOCS_CMAKE_BOOL=	Mapper_WITH_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_USE=	QT=assistant_run
EXAMPLES_CMAKE_BOOL=	Mapper_WITH_EXAMPLES
GDAL_DESC=	Use the GDAL library
GDAL_CMAKE_BOOL=	Mapper_USE_GDAL
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
NLS_CMAKE_BOOL=	Mapper_WITH_NLS
NLS_USE=	QT=linguisttools_build
NLS_USES=	gettext-runtime
POSITIONING_DESC=	GPS positioning
POSITIONING_CMAKE_ON=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Positioning=0 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5Sensors=0 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5SerialPort=0
POSITIONING_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Positioning=1 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5Sensors=1 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5SerialPort=1
POSITIONING_USE=	QT=location,sensors,serialport
TEST_CMAKE_BOOL=	Mapper_WITH_TEST
TEST_USE=	QT=testlib_build
TEST_TEST_TARGET=	test
TIFF_DESC=	Support for TIFF
TIFF_USE=	QT=imageformats

.include <bsd.port.mk>
