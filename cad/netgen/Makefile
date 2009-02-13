# New ports collection makefile for:  netgen
# Date created:               29 April 2004
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netgen
PORTVERSION=	4.4
PORTREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	http://www.hpfem.jku.at/cgi/download.cgi?ID=
DISTNAME=	ngs${PORTVERSION:S/.//g}

MAINTAINER=	stephen@math.missouri.edu
COMMENT=	An automatic 3D tetrahedral mesh generator

LIB_DEPENDS=	tix8184:${PORTSDIR}/x11-toolkits/tix

USE_GMAKE=	yes
USE_TK=		yes
USE_TK_BUILD=	yes
USE_GL=		yes
USE_XORG=	xmu xi

ALL_TARGET=	ng

FETCH_BEFORE_ARGS+=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

.if defined(WITH_OCC)
LIB_DEPENDS+=	TKernel.0:${PORTSDIR}/cad/opencascade
CXXFLAGS+=	-DOCCGEOMETRY -DOCC52 -DHAVE_WOK_CONFIG_H -DHAVE_CONFIG_H -D${ARCH} -I${LOCALBASE}/OpenCAS/ros/inc
.endif

TUTOS=		boxcyl.geo cone.geo cube.geo cubeandspheres.geo cubemcyl.geo		\
		cubemsphere.geo cylinder.geo cylsphere.geo demo2d.in2d ellipsoid.geo	\
		ellipticcyl.geo fichera.geo hinge.stl lshape3d.geo manyholes.geo	\
		matrix.geo part1.stl period.geo sculpture.geo shaft.geo sphere.geo	\
		sphereincube.geo square.in2d test.msz trafo.geo twobricks.geo		\
		twocubes.geo twocyl.geo

DIRTCL=		demoapp ngsolve ngtcltk

MACHINE=	${OPSYS:U}

MAKE_ENV=	TK_VER=${TK_VER} TCL_VER=${TCL_VER}	\
		TCL_INCLUDEDIR="${TCL_INCLUDEDIR}"	\
		TK_INCLUDEDIR="${TK_INCLUDEDIR}"	\
		MACHINE=${MACHINE} MAKE=${GMAKE}	\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		internal gcc error (Bug 23159)
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_OCC if IGES and STEP support is required."
	@${ECHO_MSG}

pre-configure:
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"		\
		${WRKSRC}/ngtcltk/ngappinit.cpp
.if defined(WITH_OCC)
	${REINPLACE_CMD} -e 's|^# occlib|occlib|;s|-pthread|${PTHREAD_LIBS}|'	\
		${WRKSRC}/libsrc/makefile.mach.FREEBSD	\
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|^#OCC|OCC|;s|ros/lin/|ros/bsd/|;	\
		s|/opt/OpenCASCADE5.2|${LOCALBASE}/OpenCAS|'	\
		${WRKSRC}/Makefile
.endif

do-install:
	${MKDIR} ${DIRTCL:S|^|${PREFIX}/netgen/|g}
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/netgen
	${LN} -s ${PREFIX}/netgen/ng ${PREFIX}/bin
.for tcls in . ${DIRTCL}
	${CP} ${WRKSRC}/${tcls}/*.tcl ${PREFIX}/netgen/${tcls}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/tutorials ${DOCSDIR}/ngsolve
	${INSTALL_DATA} ${WRKSRC}/doc/ng4.pdf ${DOCSDIR}
. for doc in ${TUTOS}
	${INSTALL_DATA} ${WRKSRC}/tutorials/${doc} ${DOCSDIR}/tutorials
. endfor
	${CP} ${WRKSRC}/ngsolve/doc/* ${DOCSDIR}/ngsolve
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
