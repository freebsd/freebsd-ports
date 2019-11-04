# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	gmsh
DISTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://gmsh.info/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DIST_SUBDIR=	gmsh

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Automatic 3D finite element mesh generator

LICENSE=	AGPLv3+ APACHE20 GPLv3+ GPLv2+ LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libgmp.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libsz.so:science/szip \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	getdp:science/getdp

USES=		blaslapack compiler:c++11-lang cmake fortran gl jpeg tar:tgz \
		xorg
USE_GL=		gl glu
USE_XORG=	x11 xcursor xext xinerama xfixes xft xrender

CMAKE_ARGS=	-DCMAKE_SKIP_RPATH:BOOL=YES

OPTIONS_DEFINE=	CGNS DOCS MED OCC SHARED STATIC
OPTIONS_DEFAULT=	CGNS MED OCC
OPTIONS_SUB=	yes

CGNS_DESC=	Enable CGNS mesh import
MED_DESC=	Enable MED mesh and post file formats
OCC_DESC=	Enable OpenCASCADE geometrical models
SHARED_DESC=	Build shared library and install header files
STATIC_DESC=	Build static library

PLIST_SUB=	VER=${PORTVERSION} VE=${PORTVERSION:R}

# TODO
# Dependencies against PythonLibs, swig and petsc are found and registered if
# installed
# => add knobs to handle them.

CGNS_CMAKE_BOOL=	ENABLE_CGNS
CGNS_LIB_DEPENDS=	libcgns.so:science/cgnslib
DOCS_CMAKE_BOOL=	INSTALL_DOCS
MED_CMAKE_BOOL=		ENABLE_MED
MED_LIB_DEPENDS=	libmed.so:french/med
OCC_CMAKE_BOOL=		ENABLE_OCC
OCC_CMAKE_ON=		-DOCC_INC=${LOCALBASE}/include/OpenCASCADE
OCC_LIB_DEPENDS=	libopenblas.so:math/openblas libTKernel.so:cad/opencascade
OCC_USES=		gnome
OCC_USE=		gnome=cairo
SHARED_CMAKE_BOOL=	ENABLE_BUILD_SHARED
SHARED_USE=		LDCONFIG=yes
STATIC_CMAKE_BOOL=	ENABLE_BUILD_LIB

post-patch:
	@${REINPLACE_CMD} -e "s|share/doc/gmsh|${DOCSDIR_REL}|" \
		-e 's|share/man/man1|man/man1|' ${WRKSRC}/CMakeLists.txt

post-install-SHARED-on:
	${RM} -r ${STAGEDIR}/wrkdirs

.include <bsd.port.mk>
