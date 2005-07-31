# New ports collection makefile for:  netgen
# Date created:               29 April 2004
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netgen
PORTVERSION=	4.4
CATEGORIES=	cad
MASTER_SITES=	http://www.hpfem.jku.at/netgen/
DISTNAME=	ngs${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D tetrahedral mesh generator

LIB_DEPENDS=	tix8184:${PORTSDIR}/x11-toolkits/tix

USE_GCC=	3.3	# netgen-4.4 is BROKEN with gcc-3.4 on 5.3-STABLE.
USE_GMAKE=	yes
USE_GL=		yes
USE_REINPLACE=	yes

ALL_TARGET=	ng

TUTOS=		boxcyl.geo cone.geo cube.geo cubeandspheres.geo cubemcyl.geo		\
		cubemsphere.geo cylinder.geo cylsphere.geo demo2d.in2d ellipsoid.geo	\
		ellipticcyl.geo fichera.geo hinge.stl lshape3d.geo manyholes.geo	\
		matrix.geo part1.stl period.geo sculpture.geo shaft.geo sphere.geo	\
		sphereincube.geo square.in2d test.msz trafo.geo twobricks.geo		\
		twocubes.geo twocyl.geo

DIRTCL=		demoapp ngsolve ngtcltk

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"internal gcc error (Bug 23159)"
.endif

TK_VER?=	8.4
SHORT_TK_VER=	${TK_VER:S/.//}

TCL_VER?=	${TK_VER}
SHORT_TCL_VER=	${TCL_VER:S/.//}

LIB_DEPENDS+=	tcl${SHORT_TCL_VER}:${PORTSDIR}/lang/tcl${SHORT_TCL_VER}	\
		tk${SHORT_TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}

MACHINE=	${OPSYS:U}

MAKE_ENV=	TK_VER=${TK_VER} TCL_VER=${TCL_VER}	\
		MACHINE=${MACHINE} MAKE=${GMAKE}	\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

pre-configure:
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"		\
		${WRKSRC}/ngtcltk/ngappinit.cpp

do-install:
	${MKDIR} ${DIRTCL:S|^|${PREFIX}/netgen/|g}
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/netgen
	${LN} -s ${PREFIX}/netgen/ng ${PREFIX}/bin
.for tcls in . ${DIRTCL}
	${CP} ${WRKSRC}/${tcls}/*.tcl ${PREFIX}/netgen/${tcls}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/tutorials ${DOCSDIR}/ngsolve
	@${INSTALL_DATA} ${WRKSRC}/doc/ng4.pdf ${DOCSDIR}
. for doc in ${TUTOS}
	@${INSTALL_DATA} ${WRKSRC}/tutorials/${doc} ${DOCSDIR}/tutorials
. endfor
	@${CP} ${WRKSRC}/ngsolve/doc/* ${DOCSDIR}/ngsolve
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
