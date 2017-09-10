# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	gmsh
PORTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://gmsh.info/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DIST_SUBDIR=	gmsh

MAINTAINER=	jrm@FreeBSD.org
COMMENT?=	Automatic 3D finite element mesh generator

LICENSE=	AGPLv3+ APACHE20 GPLv3+ GPLv2+ LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ = ${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libgmp.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libsz.so:science/szip
RUN_DEPENDS=	getdp:science/getdp

BROKEN_powerpc64=Does not build on powerpc64
BROKEN_FreeBSD_12_i386=Does not build on FreeBSD 12 i386 due to a clang bug: https://llvm.org/bugs/show_bug.cgi?id=21903

SLAVEDIRS=	cad/gmsh-occ

USES=		blaslapack cmake fortran jpeg tar:tgz
USE_GL=		gl glu
USE_XORG=	x11 xcursor xext xinerama xfixes xft

MAKE_JOBS_UNSAFE=yes

CMAKE_ARGS=	-DCMAKE_SKIP_RPATH:BOOL=YES

OPTIONS_DEFINE=	CGNS MED OCC SHARED STATIC
OPTIONS_DEFAULT=MED

CGNS_DESC=	Enable experimental CGNS mesh support
MED_DESC=	Enable MED mesh and post file formats
OCC_DESC=	Enable Open CASCADE geometrical models
SHARED_DESC=	Build shared library and install header files
STATIC_DESC=	Build static library

OPTIONS_SUB=	yes
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
OCC_CFLAGS=		-DHAVE_CONFIG_H -DHAVE_WOK_CONFIG_H -DFREEBSD
OCC_CMAKE_BOOL=		ENABLE_OCC
OCC_CMAKE_ON=		-DOCC_INC=${LOCALBASE}/include/OpenCASCADE
OCC_CONFLICTS=		gmsh-[23].*
OCC_CONFLICTS_OFF=	gmsh-occ-[23].*
OCC_LIB_DEPENDS=	libopenblas.so:math/openblas libTKernel.so:cad/opencascade
OCC_USE=		gnome=cairo
SHARED_ALL_TARGET=	shared
SHARED_CMAKE_BOOL=	ENABLE_BUILD_SHARED
SHARED_VARS=		USE_LDCONFIG=yes
STATIC_ALL_TARGET=	lib
STATIC_CMAKE_BOOL=	ENABLE_BUILD_LIB

post-patch:
	@${REINPLACE_CMD} -e "s|share/doc/gmsh|${DOCSDIR_REL}|" \
		-e 's|share/man/man1|man/man1|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
