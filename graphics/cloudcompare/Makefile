PORTNAME=	cloudcompare
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.4
PORTREVISION=	17
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D point cloud processing software
WWW=		https://www.cloudcompare.org/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

USES=		cmake compiler:c++11-lang localbase:ldflags qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	CloudCompare
GH_PROJECT=	${GH_ACCOUNT}
GH_TUPLE=	CloudCompare:CCCoreLib:f0d5450:CloudCompare/libs/qCC_db/extern/CCCoreLib

USE_QT=		concurrent core gui opengl printsupport widgets buildtools:build qmake:build svg linguisttools:build
USE_LDCONFIG=	yes

# PDAL support disabled ATM
# plugins/core/IO/qPDALIO/src/LASFilter.cpp:1360:24: error: no member named 'incompatibleSrs' in 'pdal::LasHeader'
OPTIONS_DEFINE=	DXFLIB GAMEPAD GDAL PLUGINS SHAPELIB
OPTIONS_DEFAULT=DXFLIB GAMEPAD GDAL PLUGINS SHAPELIB
OPTIONS_SUB=	yes

DXFLIB_DESC=	Enable AutoCAD DXF file support
GAMEPAD_DESC=	Enable Qt gamepad support
GDAL_DESC=	Enable raster file support
PDAL_DESC=	Enable point cloud data support
SHAPELIB_DESC=	Enable shape file support

DXFLIB_CMAKE_BOOL=	OPTION_USE_DXF_LIB

GAMEPAD_USE=		QT=gamepad
GAMEPAD_CMAKE_BOOL=	OPTION_SUPPORT_GAMEPADS

GDAL_CMAKE_BOOL=	OPTION_USE_GDAL
GDAL_CMAKE_ON=		-DGDAL_INCLUDE_DIR=${PREFIX}/include \
			-DGDAL_LIBRARY=${PREFIX}/lib/libgdal.so
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal

PDAL_CMAKE_BOOL=	PLUGIN_IO_QPDAL
PDAL_CMAKE_ON=		-DJSON_ROOT_DIR=${PREFIX}/include/jsoncpp
PDAL_LIB_DEPENDS=	libpdal_base.so:math/pdal

SHAPELIB_CMAKE_BOOL=	OPTION_USE_SHAPE_LIB
SHAPELIB_LIB_DEPENDS=	libshp.so:devel/shapelib

PLUGINS_USES=		eigen:3 gl jpeg xorg
PLUGINS_CMAKE_BOOL=	PLUGIN_STANDARD_QANIMATION	\
			PLUGIN_STANDARD_QBROOM		\
			PLUGIN_STANDARD_QCOMPASS	\
			PLUGIN_STANDARD_QCSF		\
			PLUGIN_IO_QCSV_MATRIX		\
			PLUGIN_GL_QEDL			\
			PLUGIN_STANDARD_QFACETS		\
			PLUGIN_STANDARD_QHPR		\
			PLUGIN_STANDARD_QM3C2		\
			PLUGIN_STANDARD_QPCV		\
			PLUGIN_IO_QPHOTOSCAN		\
			PLUGIN_STANDARD_QRANSAC_SD	\
			PLUGIN_STANDARD_QSRA		\
			PLUGIN_GL_QSSAO # plugins requiring rare external libs are left out, TODO maybe add some of them?
PLUGINS_CMAKE_ON=	-DEIGEN_ROOT_DIR:BOOL=${LOCALBASE}/include/eigen3
PLUGINS_CXXFLAGS=	${PLUGINS_CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
PLUGINS_CXXFLAGS_clang=	-Wno-narrowing
PLUGINS_CXXFLAGS+=	-DEIGEN_DONT_PARALLELIZE # OpenMP is broken in cmake: see bug#223678
PLUGINS_USE=		XORG=ice,sm,x11,xext,xt GL=gl,glu
PLUGINS_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libexpat.so:textproc/expat2 \
			libflann_cpp.so:math/flann \
			libfreetype.so:print/freetype2 \
			libpng.so:graphics/png \
			libtiff.so:graphics/tiff \
			libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}
PLUGINS_IMPLIES=	SHAPELIB

pre-configure:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},1' ${WRKSRC}/snap/gui/ccViewer.desktop ${WRKSRC}/snap/gui/cloudcompare.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/snap/gui/ccViewer.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/snap/gui/ccViewer.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/snap/gui/cloudcompare.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/snap/gui/cloudcompare.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
