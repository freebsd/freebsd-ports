PORTNAME=	openorienteering-mapper
PORTVERSION=	0.9.5
DISTVERSIONPREFIX=	v
PORTREVISION=	14
CATEGORIES=	graphics geography

MAINTAINER=	sikmir@gmail.com
COMMENT=	Map drawing program from OpenOrienteering
WWW=		https://www.openorienteering.org/apps/mapper/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PATCH_SITES=	https://github.com/OpenOrienteering/mapper/commit/
PATCHFILES=	69977dfd4cbb8608aafa8ca8b5388d4983f5430a.patch:-p1 \
		a3cb8e4518f8d15a6938c9b1620c35703788c6ff.patch:-p1

LIB_DEPENDS=	libpolyclipping.so:graphics/polyclipping \
		libproj.so:graphics/proj

USES=		cmake:noninja compiler:c++14-lang \
		desktop-file-utils gmake qt:5 shared-mime-info
USE_QT=		buildtools:build help qmake:build concurrent core gui \
		network printsupport testlib widgets
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
DOCS_USE=	QT=assistant:run
EXAMPLES_CMAKE_BOOL=	Mapper_WITH_EXAMPLES
GDAL_DESC=	Use the GDAL library
GDAL_CMAKE_BOOL=	Mapper_USE_GDAL
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
NLS_CMAKE_BOOL=	Mapper_WITH_NLS
NLS_USE=	QT=linguisttools:build
NLS_USES=	gettext-runtime
POSITIONING_DESC=	GPS positioning
POSITIONING_CMAKE_ON=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Positioning=0 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5Sensors=0 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5SerialPort=0
POSITIONING_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Positioning=1 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5Sensors=1 -DCMAKE_DISABLE_FIND_PACKAGE_Qt5SerialPort=1
POSITIONING_USE=	QT=location,sensors,serialport
TEST_CMAKE_BOOL=	Mapper_WITH_TEST
TEST_USE=	QT=testlib:build
TEST_TEST_TARGET=	test
TIFF_DESC=	Support for TIFF
TIFF_USE=	QT=imageformats

.include <bsd.port.mk>
