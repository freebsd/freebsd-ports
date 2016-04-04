# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	gmsh
PORTVERSION=	2.12.0
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/ \
		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	gmsh
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Automatic 3D finite element mesh generator

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libpng.so:graphics/png \
		liblapack.so:math/lapack
RUN_DEPENDS=	getdp:science/getdp

BROKEN_powerpc64=	Does not build on powerpc64

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

SLAVEDIRS=	cad/gmsh-occ

USES=		cmake fortran gmake jpeg tar:tgz
USE_GL=		yes
ALL_TARGET=	all

MAKE_JOBS_UNSAFE=	yes

CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=YES

OPTIONS_DEFINE=	STATIC_LIB SHARED_LIB TETGEN METIS TAUCS MED CGNS GMM OCC
OPTIONS_DEFAULT=	DOCS STATIC_LIB SHARED_LIB TETGEN METIS MED CGNS GMM

STATIC_LIB_DESC=	Build static library
SHARED_LIB_DESC=	Build shared library
TETGEN_LIB_DESC=	Enable tetgen as an alternative 3D mesh generator
METIS_LIB_DESC=		Enable metis as an alternative 3D mesh generator
TAUCS_LIB_DESC=		Enable the Taucs linear algebra solver
MED_LIB_DESC=		Enable MED support
CGNS_LIB_DESC=		Enable CGNS support
GMM_LIB_DESC=		Enable gmm++ support
OCC_LIB_DESC=		Enable STEP, IGES and BREP support

OPTIONS_SUB=		yes

STATIC_LIB_CMAKE_ON=	-DENABLE_BUILD_LIB=ON
STATIC_LIB_ALL_TARGET=	lib
SHARED_LIB_CMAKE_ON=	-DENABLE_BUILD_SHARED=ON
SHARED_LIB_ALL_TARGET=	shared
SHARED_LIB_VARS=	use_ldconfig=yes
PLIST_SUB+=		SHARED_LIB="" VER=${PORTVERSION} VE=${PORTVERSION:R}
DOCS_CMAKE_OFF=		-DINSTALL_DOCS=OFF
TETGEN_CMAKE_ON=	-DENABLE_TETGEN=ON
TETGEN_CMAKE_OFF=	-DENABLE_TETGEN=OFF
TETGEN_VARS=		"no_cdrom=Contact appropriate authors for commercial purposes if including Tetgen or Metis"
METIS_CMAKE_ON=	-DENABLE_METIS=ON
METIS_CMAKE_OFF=	-DENABLE_METIS=OFF
METIS_VARS=		"no_cdrom=Contact appropriate authors for commercial purposes if including Tetgen or Metis"
METIS_VARS=		distfiles+=manual.pdf
TAUCS_LIB_DEPENDS=	libtaucs.so:math/taucs
TAUCS_CMAKE_ON=		-DENABLE_TAUCS=ON
TAUCS_CMAKE_OFF=	-DENABLE_TAUCS=OFF
MED_LIB_DEPENDS=	libmed.so:french/med
MED_CMAKE_ON=		-DENABLE_MED=ON
MED_CMAKE_OFF=		-DENABLE_MED=OFF
CGNS_LIB_DEPENDS=	libcgns.so:science/cgnslib
CGNS_CMAKE_ON=		-DENABLE_CGNS=ON
CGNS_CMAKE_OFF=		-DENABLE_CGNS=OFF
GMM_CMAKE_OFF=		-DENABLE_GMM=OFF
OCC_LIB_DEPENDS=	libTKernel.so:cad/opencascade
OCC_CMAKE_ON=		-DENABLE_OCC=ON -DOCC_INC=${LOCALBASE}/include/OpenCASCADE
OCC_CFLAGS=		-DHAVE_CONFIG_H -DHAVE_WOK_CONFIG_H -DFREEBSD
OCC_CONFLICTS=		gmsh-2.*
OCC_CMAKE_OFF=		-DENABLE_OCC=OFF
OCC_CONFLICTS_OFF=	gmsh-occ-2.*

.include <bsd.port.options.mk>

# Even though the taucs port pulls in the metis port, we will still need
# METIS set when TAUCS is set, otherwise the linker does not find the
# libraries installed by the metis port.
.if ${PORT_OPTIONS:MTAUCS} && !${PORT_OPTIONS:MMETIS}
IGNORE=		METIS must be set if TAUCS is set
.endif

.if !${PORT_OPTIONS:MMETIS} && ${PORT_OPTIONS:MDOCS}
IGNORE=		the license for Metis requires that its documentation is included
.endif

# TODO
# Dependencies against PythonLibs, swig and petsc are found and registered if installed
# => add knobs to handle them.

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf ${WRKDIR}
	${TOUCH} ${PKGMESSAGE}
.if ${PORT_OPTIONS:MTETGEN}
	@${ECHO} >> ${PKGMESSAGE}
	@${ECHO} "The FreeBSD project has been granted redistribution rights" >> ${PKGMESSAGE}
	@${ECHO} "but anyone attempting to redistribute Gmsh with Tetgen" >> ${PKGMESSAGE}
	@${ECHO} "for strict commercial purposes must still contact the author" >> ${PKGMESSAGE}
	@${ECHO} "(Hang Si) and license the code." >> ${PKGMESSAGE}
.endif
.if ${PORT_OPTIONS:MMETIS}
	@${ECHO} >> ${PKGMESSAGE}
	@${ECHO} "The FreeBSD project has been granted redistribution rights" >> ${PKGMESSAGE}
	@${ECHO} "but anyone attempting to redistribute Gmsh with Metis" >> ${PKGMESSAGE}
	@${ECHO} "must still contact the author" >> ${PKGMESSAGE}
	@${ECHO} "http://glaros.dtc.umn.edu/gkhome/metis/metis/faq?q=metis/metis/faq#distribute" >> ${PKGMESSAGE}
	@${ECHO} "\"A Fast and Highly Quality Multilevel Scheme for Partitioning Irregular Graphs\". George Karypis and Vipin Kumar. SIAM Journal on Scientific Computing, Vol. 20, No. 1, pp. 359-392, 1999." >> ${PKGMESSAGE}
.endif
.if ${PORT_OPTIONS:MTAUCS}
	@${ECHO} >> ${PKGMESSAGE}
	@${ECHO} "There might be licensing issues with using Taucs with Gmsh" >> ${PKGMESSAGE}
	@${ECHO} "because Taucs requires Metis." >> ${PKGMESSAGE}
.endif

pre-configure:
	${REINPLACE_CMD} -e s+share/doc/gmsh+${DOCSDIR_REL}+ \
		-e s+share/man/man1+man/man1+ ${WRKSRC}/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MMETIS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/metis
	${INSTALL_DATA} ${WRKDIR}/manual.pdf ${STAGEDIR}${DOCSDIR}/metis
.endif

.include <bsd.port.post.mk>
