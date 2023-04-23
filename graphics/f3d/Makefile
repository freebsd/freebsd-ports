PORTNAME=	f3d
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
PORTREVISION=	7
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/f3d-app/f3d/commit/
PATCHFILES=	cc108300b44981b530aa3ad72c971c889e6bf3e2.diff:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and minimalist 3D viewer
WWW=		https://f3d-app.github.io/f3d/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libImath-3_1.so:math/Imath \
		libnetcdf.so:science/netcdf \
		libvtkCommonMisc-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake:testing compiler:c++17-lang desktop-file-utils gl tcl tk xorg
USE_GL=		gl glu
USE_XORG=	ice sm x11 xt

USE_GITHUB=	yes
GH_ACCOUNT=	f3d-app

CMAKE_OFF=	F3D_STRICT_BUILD # disable -Werror

OPTIONS_GROUP=			MODULES
OPTIONS_GROUP_MODULES=		ALEMBIC ASSIMP EXODUS EXTERNAL_RENDERING OCCT RAYTRACING
OPTIONS_DEFAULT=		ALEMBIC ASSIMP EXODUS OCCT

MODULES_DESC=			Build modules:

ALEMBIC_DESC=			Alembic module (ABC files)
ALEMBIC_CMAKE_BOOL=		F3D_MODULE_ALEMBIC
ALEMBIC_LIB_DEPENDS=		libAlembic.so:graphics/alembic

ASSIMP_DESC=			Assimp module (FBX, OFF, DAE and DXF files)
ASSIMP_CMAKE_BOOL=		F3D_MODULE_ASSIMP
ASSIMP_LIB_DEPENDS=		libassimp.so:multimedia/assimp

EXODUS_DESC=			ExodusII module
EXODUS_CMAKE_BOOL=		F3D_MODULE_EXODUS

EXTERNAL_RENDERING_DESC=	External rendering module
EXTERNAL_RENDERING_CMAKE_BOOL=	F3D_MODULE_EXTERNAL_RENDERING
EXTERNAL_RENDERING_BROKEN=	Requires VTK::RenderingExternal enabled in VTK

OCCT_DESC=			OpenCASCADE module (STEP and IGES files)
OCCT_USES=			localbase:ldflags
OCCT_CMAKE_BOOL=		F3D_MODULE_OCCT
OCCT_LIB_DEPENDS=		libTKBRep.so:cad/opencascade \
				libdraco.so:archivers/draco
OCCT_CMAKE_ON=			-DOpenCASCADE_DIR=${LOCALBASE}/lib/cmake

RAYTRACING_DESC=		Raytracing module
RAYTRACING_CMAKE_BOOL=		F3D_MODULE_RAYTRACING
RAYTRACING_BROKEN=		Requires VTK::RenderingRayTracing enabled in VTK

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
