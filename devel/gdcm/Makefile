# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdcm
PORTVERSION=	${GDCM_MAJOR}.${GDCM_MINOR}.${GDCM_PATCH}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/gdcm/gdcm%202.x/GDCM%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Grassroots DICOM library

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libopenjpeg.so:graphics/openjpeg15 \
		libexpat.so:textproc/expat2

OPTIONS_DEFINE=		DOXYGEN
OPTIONS_RADIO=		VTK
OPTIONS_RADIO_VTK=	VTK5 VTK6
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			docbook-xsl-ns>0:textproc/docbook-xsl-ns
DOXYGEN_USES=		ghostscript
DOXYGEN_USE=		gnome=libxslt:build tex=latex:build
DOXYGEN_CMAKE_ON=	-DGDCM_DOCUMENTATION:BOOL=ON \
			-DGDCM_PDF_DOCUMENTATION:BOOL=OFF \
			-DGDCM_INSTALL_MAN_DIR:PATH=man \
			-DGDCM_INSTALL_DOC_DIR:PATH=${DOCSDIR_REL}
DOXYGEN_CMAKE_OFF=	-DGDCM_DOCUMENTATION:BOOL=OFF

VTK5_DESC=		Build VTK 5 integration classes
VTK5_LIB_DEPENDS=	libvtkHybrid.so:math/vtk5
VTK5_CMAKE_ON=		-DGDCM_USE_VTK:BOOL=ON \
			-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-${VTK5_VERSION}
VTK6_DESC=		Build VTK 6 integration classes
VTK6_LIB_DEPENDS=	libvtkCommonCore-${VTK6_VERSION}.so:math/vtk6
VTK6_CMAKE_ON=		-DGDCM_USE_VTK:BOOL=ON \
			-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-${VTK6_VERSION}

# Change this when updating the port
GDCM_MAJOR=	2
GDCM_MINOR=	6
GDCM_PATCH=	3

# Change this whenever VTK is updated
VTK5_VERSION=	5.10
VTK6_VERSION=	6.2

USES=		alias cmake:outsource tar:bzip2
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include
CMAKE_ARGS=	-DGDCM_USE_SYSTEM_OPENSSL:BOOL=ON \
		-DGDCM_USE_SYSTEM_EXPAT:BOOL=ON \
		-DGDCM_USE_SYSTEM_OPENJPEG:BOOL=ON \
		-DGDCM_USE_SYSTEM_ZLIB:BOOL=ON \
		-DGDCM_BUILD_APPLICATIONS:BOOL=ON \
		-DGDCM_BUILD_SHARED_LIBS:BOOL=ON \
		-DGDCM_BUILD_EXAMPLES:BOOL=OFF \
		-DGDCM_INSTALL_DATA_DIR:PATH=${DATADIR_REL}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVTK5} || ${PORT_OPTIONS:MVTK6}
DESKTOP_ENTRIES="Gdcmviewer" "Simple DICOM Viewer" "" "gdcmviewer" "" ""
PLIST_SUB+=	VTK=""
.else
PLIST_SUB+=	VTK="@comment "
.endif

PLIST_SUB+=	GDCM_MAJOR="${GDCM_MAJOR}" \
		GDCM_MINOR="${GDCM_MINOR}" \
		GDCM_PATCH="${GDCM_PATCH}"

pre-build-DOXYGEN-on:
	(cd ${WRKSRC}/Utilities/doxygen \
		&& ${LOCALBASE}/bin/doxygen -u doxyfile.in)

post-install-DOXYGEN-on:
	@(${FIND} ${STAGEDIR}${DOCSDIR} -type f | ${SED} -e \
		"s|^${STAGEDIR}${PREFIX}/||" >> ${TMPPLIST})

.include <bsd.port.mk>
