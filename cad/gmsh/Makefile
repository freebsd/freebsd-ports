PORTNAME=	gmsh
DISTVERSION=	5.0.0-git
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	LOCAL/thierry
DISTNAME=	${PORTNAME}-master-23c47b0e6a91f2f67afcbe3bf9ad1b5c253e96e2
DIST_SUBDIR=	gmsh

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Automatic 3D finite element mesh generator
WWW=		https://gmsh.info/

LICENSE=	AGPLv3+ APACHE20 GPLv3+ GPLv2+ LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	getdp:science/getdp \
		gmm++>0:math/gmm++
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libgmp.so:math/gmp \
		libmmg.so:science/mmg \
		libmetis.so:math/metis \
		libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libsz.so:science/libaec \
		libmathex.so:math/mathex \
		libalglib.so:math/alglib \
		libvoro++.so:science/voro++ \
		libfreetype.so:print/freetype2 \
		libtinyxml2.so:textproc/tinyxml2 \
		${LIB_DEPENDS_${ARCH}}
RUN_DEPENDS=	getdp:science/getdp

USES=		bison compiler:c++17-lang cmake:testing eigen:3 fortran gl	\
		jpeg localbase tar:tgz xorg

#USE_GITLAB=	yes
#GL_SITE=	https://gitlab.onelab.info/gmsh/gmsh
#GL_TAGNAME=	23c47b0e6a91f2f67afcbe3bf9ad1b5c253e96e2
WRKSRC=		${WRKDIR}/gmsh-master

# Only for 64 bits ARCHs
LIB_DEPENDS_aarch64=	libmesquite.so:math/mesquite
LIB_DEPENDS_amd64=	libmesquite.so:math/mesquite
LIB_DEPENDS_powerpc64=	libmesquite.so:math/mesquite
LIB_DEPENDS_powerpc64le=libmesquite.so:math/mesquite

USE_GL=		gl glu
USE_XORG=	ice sm x11 xcursor xext xinerama xfixes xft xrender
USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_BUILD_DYNAMIC	\
		ENABLE_BUILD_SHARED	\
		ENABLE_SYSTEM_CONTRIB

LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		CGNS DOCS MED OCC SLEPC STATIC
OPTIONS_DEFAULT=	CGNS MED OCC SLEPC
OPTIONS_SUB=	yes

CGNS_DESC=	Enable CGNS mesh import
MED_DESC=	Enable MED mesh and post file formats
OCC_DESC=	Enable OpenCASCADE geometrical models
SLEPC_DESC=	Enable PETSc and SLEPc solvers
STATIC_DESC=	Build static library

PLIST_SUB=	VER=${PORTVERSION} VE=${PORTVERSION:R}

# TODO
# Dependencies against PythonLibs and swig are found and registered if
# installed
# => add knobs to handle them.

CGNS_CMAKE_BOOL=	ENABLE_CGNS
CGNS_LIB_DEPENDS=	libcgns.so:science/cgnslib
DOCS_USES=		makeinfo
MED_CMAKE_BOOL=		ENABLE_MED
MED_LIB_DEPENDS=	libmed.so:french/med
MED_USES=		mpi
MED_LDFLAGS=		${MPI_LIBS}
OCC_CMAKE_BOOL=		ENABLE_OCC
OCC_CMAKE_ON=		-DOCC_INC=${LOCALBASE}/include/OpenCASCADE
OCC_LIB_DEPENDS=	libopenblas.so:math/openblas libTKernel.so:cad/opencascade
OCC_USES=		gnome
OCC_USE=		gnome=cairo
SLEPC_CMAKE_BOOL=	ENABLE_PETSC	\
			ENABLE_SLEPC
SLEPC_LIB_DEPENDS=	libpetsc.so:science/PETSc	\
			libslepc.so:math/slepc
STATIC_CMAKE_BOOL=	ENABLE_BUILD_LIB

.include <bsd.port.mk>
