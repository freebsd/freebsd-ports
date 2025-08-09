PORTNAME=	f3d
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and minimalist 3D viewer
WWW=		https://f3d.app/ \
		https://github.com/f3d-app/f3d

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libinotify.so:devel/libinotify \
		libnetcdf.so:science/netcdf \
		libtbb.so:devel/onetbb \
		libvtkCommonMisc-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake:testing compiler:c++17-lang desktop-file-utils gl \
		localbase:ldflags shared-mime-info tcl tk xorg
USE_GL=		gl
USE_XORG=	ice sm x11 xt
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	f3d-app

CMAKE_ON=	F3D_LINUX_INSTALL_DEFAULT_CONFIGURATION_FILE_IN_PREFIX
CMAKE_OFF=	F3D_STRICT_BUILD # disable -Werror
CMAKE_OFF+=	F3D_LINUX_APPLICATION_LINK_FILESYSTEM

LDFLAGS+=	-linotify

# dependency descroptions are in https://f3d.app/doc/dev/BUILD.html
OPTIONS_GROUP=			MODULES PLUGINS
OPTIONS_GROUP_MODULES=		EXTERNAL_RENDERING RAYTRACING
OPTIONS_GROUP_PLUGINS=		ALEMBIC ASSIMP DRACO HDF OCCT VDB
OPTIONS_DEFAULT=		ALEMBIC ASSIMP DRACO HDF OCCT # VDB
OPTIONS_SUB=			yes

MODULES_DESC=			Build modules:

ALEMBIC_DESC=			Alembic plugin (for ABC files)
ALEMBIC_CMAKE_BOOL=		F3D_PLUGIN_BUILD_ALEMBIC
ALEMBIC_LIB_DEPENDS=		libAlembic.so:graphics/alembic \
				libImath.so:math/Imath

ASSIMP_DESC=			Assimp plugin (for FBX, OFF, DAE and DXF files)
ASSIMP_CMAKE_BOOL=		F3D_PLUGIN_BUILD_ASSIMP
ASSIMP_LIB_DEPENDS=		libassimp.so:multimedia/assimp

DRACO_DESC=			Draco plugin
DRACO_CMAKE_BOOL=		F3D_PLUGIN_BUILD_DRACO
DRACO_LIB_DEPENDS=		libdraco.so:archivers/draco

EXTERNAL_RENDERING_DESC=	External rendering module
EXTERNAL_RENDERING_CMAKE_BOOL=	F3D_MODULE_EXTERNAL_RENDERING
EXTERNAL_RENDERING_BROKEN=	Requires VTK::RenderingExternal enabled in VTK

HDF_DESC=			Support for VTKHDF (.vtkhdf), ExodusII (.ex2), and NetCDF (.nc) file formats
HDF_CMAKE_BOOL=			F3D_PLUGIN_BUILD_HDF

OCCT_DESC=			OpenCASCADE plugin (for STEP and IGES files)
OCCT_USES=			localbase:ldflags
OCCT_CMAKE_BOOL=		F3D_PLUGIN_BUILD_OCCT
OCCT_LIB_DEPENDS=		libTKBRep.so:cad/opencascade
OCCT_CMAKE_ON=			-DOpenCASCADE_DIR=${LOCALBASE}/lib/cmake

VDB_DESC=			VDB plugin
VDB_CMAKE_BOOL=			F3D_PLUGIN_BUILD_VDB
VDB_BROKEN=			depends on the VTK module IOOpenVD that can't be enabled because OpenVDB doesn't install required cmake files, see https://github.com/AcademySoftwareFoundation/openvdb/issues/2058

RAYTRACING_DESC=		Raytracing module
RAYTRACING_CMAKE_BOOL=		F3D_MODULE_RAYTRACING
RAYTRACING_BROKEN=		Requires VTK::RenderingRayTracing enabled in VTK

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}
	# component-based install
	cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CMAKE_BIN} --install . --component configuration && \
		${SETENV} ${MAKE_ENV} ${CMAKE_BIN} --install . --component sdk && \
		${SETENV} ${MAKE_ENV} ${CMAKE_BIN} --install . --component mimetypes

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
