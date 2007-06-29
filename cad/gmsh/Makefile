# New ports collection makefile for:  gmsh
# Date created:               19 April 2003
# Whom:                       Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	gmsh
PORTVERSION=	2.0.7
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.geuz.org/gmsh/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D finite element mesh generator

RUN_DEPENDS=	getdp:${PORTSDIR}/science/getdp
LIB_DEPENDS=	gsl.10:${PORTSDIR}/math/gsl \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

.if defined(PACKAGE_BUILDING)
#Triangle and Tetgen are NO_CDROM
WITHOUT_TRIANGLE=	yes
WITHOUT_TETGEN=		yes
.endif

.if !defined(WITHOUT_TRIANGLE)
EXTRACT_DEPENDS+=	${NONEXISTENT}:${TRIANGLE_PORTDIR}:patch
TRIANGLE_PORTDIR=	${PORTSDIR}/math/triangle
.endif

.if !defined(WITHOUT_TETGEN)
EXTRACT_DEPENDS+=	${NONEXISTENT}:${TETGEN_PORTDIR}:patch
TETGEN_PORTDIR=		${PORTSDIR}/math/tetgen
TETGEN_SRC=		predicates.cxx tetgen.cxx tetgen.h
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-fltk-prefix=${X11BASE} \
		--with-gsl-prefix=${LOCALBASE} \
		--with-jpeg-prefix=${LOCALBASE} \
		--with-png-prefix=${LOCALBASE}
ALL_TARGET=	all utils

.if !defined(WITHOUT_HDF5) && !defined(WITHOUT_OCC)
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

.if !defined(WITHOUT_OCC)
LIB_DEPENDS+=		TKernel.0:${PORTSDIR}/cad/opencascade
CONFIGURE_ARGS+=	--enable-occ --with-occ-prefix=${LOCALBASE}/OpenCAS/ros
CONFIGURE_ENV+=		ARCH="${ARCH}"
.else
CONFIGURE_ARGS+=	--disable-occ
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		gmsh.1

pre-everything::
	@${ECHO_MSG} ""
.if !defined(WITHOUT_TRIANGLE)
	@${ECHO_MSG} "Define WITHOUT_TRIANGLE to disable Triangle as an alternative"
	@${ECHO_MSG} "isotropic 2D mesh generator."
	@${ECHO_MSG} ""
.endif
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
.if !defined(WITHOUT_OCC)
	@${ECHO_MSG} "Define WITHOUT_OCC to disable STEP, IGES and BREP support"
	@${ECHO_MSG} "(through OpenCascade)."
	@${ECHO_MSG} ""
.endif

post-extract:
.if !defined(WITHOUT_TRIANGLE)
	${CP} `cd ${TRIANGLE_PORTDIR}; ${MAKE} -V WRKSRC`/triangle.*	\
		${WRKSRC}/contrib/Triangle
.endif
.if !defined(WITHOUT_TETGEN)
	${CP} ${TETGEN_SRC:S|^|`cd ${TETGEN_PORTDIR}; ${MAKE} -V WRKSRC`/|}	\
		${WRKSRC}/contrib/Tetgen
.endif

pre-configure:
.for demo in lowmem-anim.geo
	@${REINPLACE_CMD} -e "s|../tutorial|${DOCSDIR}/tutorial|"	\
		${WRKSRC}/demos/${demo}
.endfor

do-install:
.for f in dxf2geo gmsh mshsort
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/gmsh.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} tutorial | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${FIND} demos ! -name "*.bak" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
