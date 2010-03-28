# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	2.4.2
PORTREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/ \
		http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	gmsh
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	stephen@missouri.edu
COMMENT=	An automatic 3D finite element mesh generator

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		lapack.4:${PORTSDIR}/math/lapack

SLAVEDIRS=	cad/gmsh-occ

USE_FORTRAN=	yes
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_GL=		yes
ALL_TARGET=	all

MAN1=		gmsh.1

CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=YES \
    		-DCMAKE_VERBOSE_MAKEFILE:BOOL=YES \
		-DCMAKE_USE_PTHREADS:BOOL=YES

.if !defined(WITHOUT_STATIC_LIB)
ALL_TARGET+=	lib
PLIST_SUB+=	STATIC_LIB=""
.else
PLIST_SUB+=	STATIC_LIB="@comment "
.endif

.if !defined(WITHOUT_SHARED_LIB)
ALL_TARGET+=	shared
PLIST_SUB+=	SHARED_LIB=""
USE_LDCONFIG=	yes
.else
PLIST_SUB+=	SHARED_LIB="@comment "
.endif

.if defined(NOPORTDOCS)
CMAKE_ARGS+=	-DINSTALL_DOCS=OFF
.endif

.if defined(WITHOUT_TETGEN)
CMAKE_ARGS+=	-DENABLE_TETGEN=OFF
.else
CMAKE_ARGS+=	-DENABLE_TETGEN=ON
.endif

# Even though the taucs port pulls in the metis port, we will still need
# WITHOUT_METIS not set when WITH_TAUCS is set, otherwise the linker
# does not find the libraries installed by the metis port.
.if defined(WITH_TAUCS) && defined(WITHOUT_METIS)
IGNORE=		requires that WITHOUT_METIS is not set if WITH_TAUCS is set
.endif

.if !defined(WITHOUT_METIS)
CMAKE_ARGS+=	-DENABLE_METIS=ON
.if defined(NOPORTDOCS)
IGNORE=		The license for Metis requires that its documentation is included
.endif
DISTFILES+=	manual.pdf
PLIST_SUB+=	METIS=""
.else
CMAKE_ARGS+=	-DENABLE_METIS=OFF
PLIST_SUB+=	METIS="@comment "
.endif

.if defined(WITH_TAUCS)
LIB_DEPENDS+=	taucs.1:${PORTSDIR}/math/taucs
CMAKE_ARGS+=	-DENABLE_TAUCS=ON
.else
CMAKE_ARGS+=	-DENABLE_TAUCS=OFF
.endif

.if !defined(WITHOUT_MED)
LIB_DEPENDS+=	med.2:${PORTSDIR}/french/med
CMAKE_ARGS+=	-DENABLE_MED=ON
.else
CMAKE_ARGS+=	-DENABLE_MED=OFF
.endif

.if !defined(WITHOUT_CGNS)
LIB_DEPENDS+=	cgns.0:${PORTSDIR}/science/cgnslib
CMAKE_ARGS+=	-DENABLE_CGNS=ON
.else
CMAKE_ARGS+=	-DENABLE_CGNS=OFF
.endif

.if defined(WITHOUT_GMM)
CMAKE_ARGS+=	-DENABLE_GMM=OFF
.endif

.if defined(WITH_OCC)
LIB_DEPENDS+=	TKernel.0:${PORTSDIR}/cad/opencascade
CMAKE_ARGS+=	-DENABLE_OCC=ON
CONFLICTS=	gmsh-2.*
.else
CMAKE_ARGS+=	-DENABLE_OCC=OFF
CONFLICTS=	gmsh-occ-2.*
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

CMAKE_USE_PTHREAD=	yes

pre-everything::
	@${ECHO_MSG} ""
.if !defined(WITHOUT_TETGEN)
	@${ECHO_MSG} "Define WITHOUT_TETGEN to disable Tetgen as an alternative"
	@${ECHO_MSG} "3D mesh generator."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_METIS)
	@${ECHO_MSG} "Define WITHOUT_METIS to disable Metis as an alternative"
	@${ECHO_MSG} "3D mesh generator."
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_TAUCS)
	@${ECHO_MSG} "Define WITH_TAUCS to enable the Taucs linear algebra solver."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_MED)
	@${ECHO_MSG} "Define WITHOUT_MED to disable MED support."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_CGNS)
	@${ECHO_MSG} "Define WITHOUT_CGNS to disable CGNS support."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_GMM)
	@${ECHO_MSG} "Define WITHOUT_GMM to disable gmm++ support."
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_OCC)
	@${ECHO_MSG} "Define WITH_OCC to enable STEP, IGES and BREP support"
	@${ECHO_MSG} "(through OpenCascade)."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_STATIC_LIB)
	@${ECHO_MSG} "Define WITHOUT_STATIC_LIB to avoid building and installing the static library."
	@${ECHO_MSG} "(You would want to do this to reduce build time.)"
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_SHARED_LIB)
	@${ECHO_MSG} "Define WITHOUT_SHARED_LIB to avoid building and installing the shared library."
	@${ECHO_MSG} "(You would want to do this to reduce build time.)"
	@${ECHO_MSG} ""
.endif

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf ${WRKDIR}
	${TOUCH} ${PKGMESSAGE}
.if !defined(WITHOUT_TETGEN)
	@${ECHO} >> ${PKGMESSAGE}
	@${ECHO} "The FreeBSD project has been granted redistribution rights" >> ${PKGMESSAGE}
	@${ECHO} "but anyone attempting to redistribute Gmsh with Tetgen" >> ${PKGMESSAGE}
	@${ECHO} "for strict commercial purposes must still contact the author" >> ${PKGMESSAGE}
	@${ECHO} "(Hang Si) and license the code." >> ${PKGMESSAGE}
.endif
.if !defined(WITHOUT_METIS)
	@${ECHO} >> ${PKGMESSAGE}
	@${ECHO} "The FreeBSD project has been granted redistribution rights" >> ${PKGMESSAGE}
	@${ECHO} "but anyone attempting to redistribute Gmsh with Metis" >> ${PKGMESSAGE}
	@${ECHO} "must still contact the author" >> ${PKGMESSAGE}
	@${ECHO} "http://glaros.dtc.umn.edu/gkhome/metis/metis/faq?q=metis/metis/faq#distribute" >> ${PKGMESSAGE}
	@${ECHO} "\"A Fast and Highly Quality Multilevel Scheme for Partitioning Irregular Graphs\". George Karypis and Vipin Kumar. SIAM Journal on Scientific Computing, Vol. 20, No. 1, pp. 359-392, 1999." >> ${PKGMESSAGE}
.endif
.if defined(WITH_TAUCS)
	@${ECHO} >> ${PKGMESSAGE}
	@${ECHO} "There might be licensing issues with using Taucs with Gmsh" >> ${PKGMESSAGE}
	@${ECHO} "because Taucs requires Metis." >> ${PKGMESSAGE}
.endif

post-install:
.if !defined(WITHOUT_SHARED_LIB)
	${MV} -f ${PREFIX}/lib/libGmsh.so ${PREFIX}/lib/libGmsh.so.0
	${LN} -s ${PREFIX}/lib/libGmsh.so.0 ${PREFIX}/lib/libGmsh.so
.endif
.if !defined(WITHOUT_METIS)
	${MKDIR} ${DOCSDIR}/metis
	${INSTALL_DATA} ${WRKDIR}/manual.pdf ${DOCSDIR}/metis
.endif

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
