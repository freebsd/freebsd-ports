# Created by: Nikolay Korotkiy <sikmir@gmail.com>
# $FreeBSD$

PORTNAME=	openorienteering-mapper
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics geography

MAINTAINER=	sikmir@gmail.com
COMMENT=	Map drawing program from OpenOrienteering

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolyclipping.so:graphics/polyclipping \
		libproj.so:graphics/proj

USES=		cmake:outsource,noninja compiler:c++14-lang \
		desktop-file-utils gmake shared-mime-info
USE_QT5=	buildtools_build help qmake_build core gui \
		location network printsupport sensors widgets
USE_GITHUB=	yes
GH_ACCOUNT=	OpenOrienteering
GH_PROJECT=	mapper

CMAKE_ARGS+=	-DLICENSING_PROVIDER=freebsd \
		-DMapper_PACKAGE_NAME=${PORTNAME} \
		-Wno-dev

OPTIONS_DEFINE=	DOCS EXAMPLES GDAL NLS TEST TIFF
OPTIONS_DEFAULT=	GDAL
OPTIONS_SUB=	yes
DOCS_CMAKE_BOOL=	Mapper_WITH_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_USE=	QT5=assistant_run
EXAMPLES_CMAKE_BOOL=	Mapper_WITH_EXAMPLES
GDAL_DESC=	Use the GDAL library
GDAL_CMAKE_BOOL=	Mapper_USE_GDAL
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
NLS_CMAKE_BOOL=	Mapper_WITH_NLS
NLS_BUILD_DEPENDS=	gsed:textproc/gsed
NLS_USE=	QT5=linguisttools_build
NLS_USES=	gettext-runtime
TEST_CMAKE_BOOL=	Mapper_WITH_TEST
TEST_USE=	QT5=testlib_build
TEST_TEST_TARGET=	test
TIFF_DESC=	Support for TIFF
TIFF_USE=	QT5=imageformats

.include <bsd.port.mk>
