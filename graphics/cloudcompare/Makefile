# $FreeBSD$

PORTNAME=	cloudcompare
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.3
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	3D point cloud processing software

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BROKEN_aarch64=		fails to compile: mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?

USES=		cmake compiler:c++11-lang localbase:ldflags qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	CloudCompare
GH_PROJECT=	${GH_ACCOUNT}
USE_QT=		concurrent core gui opengl printsupport widgets buildtools_build qmake_build svg linguisttools_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DXFLIB GAMEPAD GDAL PDAL SHAPELIB PLUGINS
OPTIONS_DEFAULT=	DXFLIB GAMEPAD GDAL PDAL SHAPELIB PLUGINS
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

PDAL_CMAKE_BOOL=	OPTION_PDAL_LAS
PDAL_CMAKE_ON=		-DJSON_ROOT_DIR=${PREFIX}/include/jsoncpp
PDAL_LIB_DEPENDS=	libpdal_base.so:math/pdal

SHAPELIB_CMAKE_BOOL=	OPTION_USE_SHAPE_LIB
SHAPELIB_LIB_DEPENDS=	libshp.so:devel/shapelib

PLUGINS_USES=		eigen:3 gl jpeg python:2.7 xorg
PLUGINS_CMAKE_BOOL=	INSTALL_QANIMATION_PLUGIN INSTALL_QBLUR_PLUGIN INSTALL_QBROOM_PLUGIN INSTALL_QCOMPASS_PLUGIN \
			INSTALL_QCSF_PLUGIN INSTALL_QCSV_MATRIX_IO_PLUGIN INSTALL_QDUMMY_PLUGIN INSTALL_QEDL_PLUGIN INSTALL_QFACETS_PLUGIN \
			INSTALL_QHPR_PLUGIN INSTALL_QM3C2_PLUGIN \
			INSTALL_QPCV_PLUGIN INSTALL_QPHOTOSCAN_IO_PLUGIN INSTALL_QRANSAC_SD_PLUGIN \
			INSTALL_QSRA_PLUGIN INSTALL_QSSAO_PLUGIN # plugins requiring rare external libs are left out, TODO maybe add some of them?
PLUGINS_CMAKE_ON=	-DEIGEN_ROOT_DIR:BOOL=${LOCALBASE}/include/eigen3
PLUGINS_CXXFLAGS=	${PLUGINS_CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
PLUGINS_CXXFLAGS_clang=	-Wno-narrowing
PLUGINS_CXXFLAGS+=	-DEIGEN_DONT_PARALLELIZE # OpenMP is broken in cmake: see bug#223678
PLUGINS_USE=		XORG=ice,sm,x11,xext,xt GL=gl,glu
PLUGINS_LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
			libexpat.so:textproc/expat2 \
			libflann_cpp_s.so:math/flann \
			libfreetype.so:print/freetype2 \
			libpng.so:graphics/png \
			libtiff.so:graphics/tiff \
			libvtkDomainsChemistry-6.2.so:math/vtk6
PLUGINS_IMPLIES=	SHAPELIB

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},1' ${WRKSRC}/snap/gui/ccViewer.desktop ${WRKSRC}/snap/gui/cloudcompare.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/snap/gui/ccViewer.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/snap/gui/ccViewer.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/snap/gui/cloudcompare.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/snap/gui/cloudcompare.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
