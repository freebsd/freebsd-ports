PORTNAME=	cloudcompare
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.2
CATEGORIES=	graphics

MAINTAINER=	alven@FreeBSD.org
COMMENT=	3D point cloud (and triangular mesh) editing and processing software
WWW=		https://www.cloudcompare.org/ \
		https://github.com/CloudCompare/CloudCompare/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

USES=		cmake gl qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	CloudCompare
GH_PROJECT=	${GH_ACCOUNT}
GH_TUPLE=	CloudCompare:CCCoreLib:a8ce4270:cccorelib/libs/qCC_db/extern/CCCoreLib \
		jlblancoc:nanoflann:2f54b8e:nanoflann/libs/qCC_db/extern/CCCoreLib/extern/nanoflann \
		asmaloney:libE57Format:1914b8ea:libe57format/plugins/core/IO/qE57IO/extern/libE57Format \
		google:googletest:7a7231c:googletest/plugins/core/IO/qE57IO/extern/libE57Format/test/extern/googletest \
		dgirardeau:q3DMASC:4eec6459:q3dmasc/plugins/core/Standard/q3DMASC \
		davisking:dlib:9117bd78:dlib/plugins/core/Standard/qCanupo/contrib/dlib \
		CloudCompare:qJSonRPCPlugin:1ff2dbe4:qjsonrpcplugin/plugins/core/Standard/qJSonRPCPlugin \
		hvs-ait:mplane-plugin:342ef9f5:mplaneplugin/plugins/core/Standard/qMPlane \
		CyberbuildLab:masonry-cc:0c590fb2:masonrycc/plugins/core/Standard/qMasonry \
		cloudcompare:PoissonRecon:d215dbaa:poissonrecon/plugins/core/Standard/qPoissonRecon/extern/PoissonRecon \
		truebelief:cc-treeiso-plugin:fbe6a41a:cctreeisoplugin/plugins/core/Standard/qTreeIso
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_QT=		concurrent core gui opengl printsupport widgets buildtools:build qmake:build svg linguisttools:build

OPTIONS_DEFINE=	DXFLIB GAMEPAD GDAL PLUGINS SHAPELIB
OPTIONS_DEFAULT=DXFLIB GAMEPAD GDAL PLUGINS SHAPELIB
OPTIONS_SUB=	yes

DXFLIB_DESC=	Enable AutoCAD DXF file support
GAMEPAD_DESC=	Enable Qt gamepad support
GDAL_DESC=	Enable raster file support
SHAPELIB_DESC=	Enable shape file support

DXFLIB_CMAKE_BOOL=	OPTION_USE_DXF_LIB

GAMEPAD_USE=		QT=gamepad
GAMEPAD_CMAKE_BOOL=	OPTION_SUPPORT_GAMEPADS

GDAL_CMAKE_BOOL=	OPTION_USE_GDAL
GDAL_CMAKE_ON=		-DGDAL_INCLUDE_DIR=${PREFIX}/include \
			-DGDAL_LIBRARY=${PREFIX}/lib/libgdal.so
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal

SHAPELIB_CMAKE_BOOL=	OPTION_USE_SHAPE_LIB
SHAPELIB_LIB_DEPENDS=	libshp.so:devel/shapelib

PLUGINS_USES=		eigen:3 jpeg xorg
PLUGINS_CMAKE_BOOL=	PLUGIN_STANDARD_QANIMATION	\
			PLUGIN_STANDARD_QBROOM		\
			PLUGIN_STANDARD_QCOMPASS	\
			PLUGIN_STANDARD_QCSF		\
			PLUGIN_IO_QCSV_MATRIX		\
			PLUGIN_IO_QPDAL			\
			PLUGIN_GL_QEDL			\
			PLUGIN_STANDARD_QFACETS		\
			PLUGIN_STANDARD_QHPR		\
			PLUGIN_STANDARD_QM3C2		\
			PLUGIN_STANDARD_QPCV		\
			PLUGIN_IO_QPHOTOSCAN		\
			PLUGIN_STANDARD_QRANSAC_SD	\
			PLUGIN_STANDARD_QSRA		\
			PLUGIN_GL_QSSAO # plugins requiring rare external libs are left out, TODO maybe add some of them?
PLUGINS_CMAKE_ON=	-DEIGEN_ROOT_DIR:BOOL=${LOCALBASE}/include/eigen3 -DJSON_ROOT_DIR=${LOCALBASE}/include/jsoncpp
PLUGINS_CXXFLAGS=	${PLUGINS_CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
PLUGINS_CXXFLAGS_clang=	-Wno-narrowing
PLUGINS_USE=		XORG=ice,sm,x11,xext,xt
PLUGINS_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
			libexpat.so:textproc/expat2 \
			libflann_cpp.so:math/flann \
			libfreetype.so:print/freetype2 \
			libpdalcpp.so:math/pdal \
			libpng.so:graphics/png \
			libtiff.so:graphics/tiff \
			libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}
PLUGINS_IMPLIES=	SHAPELIB

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/*.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/*.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
