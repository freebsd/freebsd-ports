# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	2.3.1
CATEGORIES=	cad
MASTER_SITES=	http://www.sfr-fresh.com/unix/privat/ \
				http://www.geuz.org/gmsh/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz

MAINTAINER=	stephen@missouri.edu
COMMENT=	An automatic 3D finite element mesh generator

RUN_DEPENDS=	getdp:${PORTSDIR}/science/getdp
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

SLAVEDIRS=	cad/gmsh-occ

.if !defined(WITHOUT_TETGEN)
EXTRACT_DEPENDS+=	${NONEXISTENT}:${TETGEN_PORTDIR}:patch
TETGEN_PORTDIR=		${PORTSDIR}/math/tetgen
TETGEN_SRC=		predicates.cxx tetgen.cxx tetgen.h
.endif

USE_FORTRAN=	yes
FORTRANLIBDIR=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``
FORTRANLIBDIR2=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``/../../../
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fltk-prefix=${LOCALBASE}	\
		--with-gsl-prefix=${LOCALBASE}	\
		--with-med-prefix=${LOCALBASE}	\
		--with-jpeg-prefix=${LOCALBASE}	\
		--with-blas-lapack-prefix=${LOCALBASE} \
		--with-png-prefix=${LOCALBASE}
USE_GMAKE=	yes
ALL_TARGET=	all utils

.if !defined(WITHOUT_HDF5) && defined(WITH_OCC)
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
.endif

.if !defined(WITHOUT_MED)
LIB_DEPENDS+=		med.2:${PORTSDIR}/french/med
CONFIGURE_ARGS+=	--enable-med --with-med-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-med
.endif

.if !defined(WITHOUT_HDF5)
LIB_DEPENDS+=		hdf5.0:${PORTSDIR}/science/hdf5
CONFIGURE_ARGS+=	--enable-hdf5 --with-hdf5-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-hdf5
.endif

.if !defined(WITHOUT_CGNS)
LIB_DEPENDS+=		cgns.0:${PORTSDIR}/science/cgnslib
CONFIGURE_ARGS+=	--enable-cgns --with-cgns-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-cgns
.endif

.if !defined(WITHOUT_GMM)
CONFIGURE_ARGS+=	--disable-gmm
.endif

# For FourierModel
.if defined(WITH_FFTW3)
LIB_DEPENDS+=		fftw3.5:${PORTSDIR}/math/fftw3
CONFIGURE_ARGS+=	--enable-fftw3 --with-fftw3-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-fftw3
.endif

.if defined(WITH_OCC)
LIB_DEPENDS+=		TKernel.0:${PORTSDIR}/cad/opencascade
CONFIGURE_ARGS+=	--enable-occ --with-occ-prefix=${LOCALBASE}/OpenCAS/ros
CONFIGURE_ENV+=		ARCH="${ARCH}"
CONFLICTS=		gmsh-2.*
.else
CONFIGURE_ARGS+=	--disable-occ
CONFLICTS=		gmsh-occ-2.*
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	CREDITS.txt FAQ.txt VERSIONS.txt gmsh.html

MAN1=		gmsh.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lcblas -lf77blas -latlas -L${FORTRANLIBDIR} -L${FORTRANLIBDIR2} -lgfortranbegin -lgfortran
LAPACK=		-lalapack ${BLAS}
ARPACK=		-larpack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack ${BLAS}
ARPACK=		-larpack
.endif

pre-everything::
	@${ECHO_MSG} ""
.if !defined(WITHOUT_TETGEN)
	@${ECHO_MSG} "Define WITHOUT_TETGEN to disable Tetgen as an alternative"
	@${ECHO_MSG} "3D mesh generator."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_MED)
	@${ECHO_MSG} "Define WITHOUT_MED to disable MED support."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_HDF5)
	@${ECHO_MSG} "Define WITHOUT_HDF5 to disable HDF5 support."
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

post-extract:
	${TOUCH} ${PKGMESSAGE}
.if !defined(WITHOUT_TETGEN)
	${CP} ${TETGEN_SRC:S|^|`cd ${TETGEN_PORTDIR}; ${MAKE} -V WRKSRC`/|}	\
		${WRKSRC}/contrib/Tetgen
	@${ECHO} >> ${PKGMESSAGE}
	@${ECHO} "The FreeBSD project has been granted redistribution rights" >> ${PKGMESSAGE}
	@${ECHO} "but anyone attempting to redistribute Gmsh with Tetgen" >> ${PKGMESSAGE}
	@${ECHO} "for strict commercial purposes must still contact the author" >> ${PKGMESSAGE}
	@${ECHO} "(Hang Si) and license the code." >> ${PKGMESSAGE}
.endif

pre-configure:
.for demo in lowmem-anim.geo
	@${REINPLACE_CMD} -e "s|../tutorial|${DOCSDIR}/tutorial|"	\
		${WRKSRC}/demos/${demo}
.endfor
	${REINPLACE_CMD} -e 's|-lcblas -latlas|%%BLAS%%|;		\
		s|-lcblas|${BLAS}|; s|%%BLAS%%|${BLAS}|;		\
		s|-llapack|${LAPACK}|' ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
.for f in dxf2geo gmsh mshsort
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/gmsh.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} tutorial | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${FIND} demos ! -name "*.bak" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
