PORTNAME=	gdcm
PORTVERSION=	${GDCM_MAJOR}.${GDCM_MINOR}.${GDCM_PATCH}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/gdcm/gdcm%20${GDCM_MAJOR}.x/GDCM%20${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Grassroots DICOM library
WWW=		https://gdcm.sourceforge.net/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg \
		libexpat.so:textproc/expat2

USES=		alias cmake compiler:c++11-lang pkgconfig python:build tar:bzip2 ssl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		VTK
OPTIONS_SUB=		yes

VTK_DESC=		Build VTK integration classes
VTK_CXXFLAGS=		-I${LOCALBASE}/include/vtk-${VTK_VERSION}
VTK_LIB_DEPENDS=	libvtkCommonCore-${VTK_VERSION}.so:math/vtk${VTK_VERSION:R}
VTK_CMAKE_ON=		-DGDCM_USE_VTK:BOOL=ON \
			-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-${VTK_VERSION}
VTK_USES=		gl
VTK_USE=		GL=glu
VTK_BROKEN=		Fails to compile with VTK-9.1, see https://sourceforge.net/p/gdcm/bugs/537/

# Change this when updating the port
GDCM_MAJOR=	3
GDCM_MINOR=	0
GDCM_PATCH=	24

# Change this whenever VTK is updated
VTK_VERSION=	9.1

CFLAGS+=	-I${LOCALBASE}/include
CMAKE_ARGS=	-DGDCM_USE_SYSTEM_OPENSSL:BOOL=ON \
		-DGDCM_USE_SYSTEM_EXPAT:BOOL=ON \
		-DGDCM_USE_SYSTEM_OPENJPEG:BOOL=ON \
		-DGDCM_USE_SYSTEM_ZLIB:BOOL=ON \
		-DGDCM_BUILD_APPLICATIONS:BOOL=ON \
		-DGDCM_BUILD_SHARED_LIBS:BOOL=ON \
		-DGDCM_BUILD_EXAMPLES:BOOL=OFF \
		-DGDCM_INSTALL_DATA_DIR:PATH=${DATADIR_REL} \
		-DGDCM_DOCUMENTATION:BOOL=OFF \
		-DGDCM_BUILD_DOCBOOK_MANPAGES:BOOL=OFF \
		-DPython3_EXECUTABLE=${PYTHON_CMD} \
		-DGDCM_DEFAULT_PYTHON_VERSION=${PYTHON_VER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVTK}
DESKTOP_ENTRIES="Gdcmviewer" "Simple DICOM Viewer" "" "gdcmviewer" "" ""
PLIST_SUB+=	VTK=""
.else
PLIST_SUB+=	VTK="@comment "
.endif

PLIST_SUB+=	GDCM_MAJOR="${GDCM_MAJOR}" \
		GDCM_MINOR="${GDCM_MINOR}" \
		GDCM_PATCH="${GDCM_PATCH}"

.include <bsd.port.mk>
