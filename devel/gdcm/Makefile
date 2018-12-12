# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdcm
PORTVERSION=	${GDCM_MAJOR}.${GDCM_MINOR}.${GDCM_PATCH}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/gdcm/gdcm%202.x/GDCM%20${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Grassroots DICOM library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	pkgconf:devel/pkgconf
LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg \
		libexpat.so:textproc/expat2

USES=		alias cmake:outsource compiler:c++11-lang tar:bzip2 ssl

OPTIONS_DEFINE=		VTK6
OPTIONS_SUB=		yes

VTK6_DESC=		Build VTK 6 integration classes
VTK6_LIB_DEPENDS=	libvtkCommonCore-${VTK6_VERSION}.so:math/vtk6
VTK6_CMAKE_ON=		-DGDCM_USE_VTK:BOOL=ON \
			-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-${VTK6_VERSION}

# Change this when updating the port
GDCM_MAJOR=	2
GDCM_MINOR=	8
GDCM_PATCH=	8

# Change this whenever VTK is updated
VTK6_VERSION=	6.2

USE_LDCONFIG=	yes
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
		-DGDCM_BUILD_DOCBOOK_MANPAGES:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVTK6}
DESKTOP_ENTRIES="Gdcmviewer" "Simple DICOM Viewer" "" "gdcmviewer" "" ""
PLIST_SUB+=	VTK=""
.else
PLIST_SUB+=	VTK="@comment "
.endif

PLIST_SUB+=	GDCM_MAJOR="${GDCM_MAJOR}" \
		GDCM_MINOR="${GDCM_MINOR}" \
		GDCM_PATCH="${GDCM_PATCH}"

.include <bsd.port.mk>
