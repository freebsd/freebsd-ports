# New ports collection makefile for:  netgen
# Date created:               29 April 2004
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netgen
PORTVERSION=	4.3.1
CATEGORIES=	cad
MASTER_SITES=	http://www.hpfem.jku.at/netgen/
DISTNAME=	ng${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic 3D tetrahedral mesh generator

LIB_DEPENDS=	tix8184:${PORTSDIR}/x11-toolkits/tix

USE_GCC=	3.4
USE_GMAKE=	yes
USE_GL=		yes
USE_REINPLACE=	yes

ALL_TARGET=	ng

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/tutorials
PORTDOCS=	boxcyl.geo cone.geo cube.geo cubeandspheres.geo cubemcyl.geo		\
		cubemsphere.geo cylinder.geo cylsphere.geo demo2d.in2d ellipsoid.geo	\
		ellipticcyl.geo fichera.geo hinge.stl lshape3d.geo manyholes.geo	\
		matrix.geo part1.stl period.geo sculpture.geo shaft.geo sphere.geo	\
		sphereincube.geo square.in2d test.msz trafo.geo twobricks.geo		\
		twocubes.geo twocyl.geo

.include <bsd.port.pre.mk>

TK_VER?=	8.4
SHORT_TK_VER=	${TK_VER:S/.//}

TCL_VER?=	${TK_VER}
SHORT_TCL_VER=	${TCL_VER:S/.//}

LIB_DEPENDS+=	tcl${SHORT_TCL_VER}:${PORTSDIR}/lang/tcl${SHORT_TCL_VER}	\
		tk${SHORT_TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}

unames!=	${UNAME} -s
MACHINE=	${unames:U}

MAKE_ENV=	TK_VER=${TK_VER} TCL_VER=${TCL_VER}	\
		MACHINE=${MACHINE} MAKE=${GMAKE}	\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

pre-configure:
	@${MV} ${WRKSRC}/libsrc/makefile.mach.LINUX			\
		${WRKSRC}/libsrc/makefile.mach.${MACHINE}
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"		\
		${WRKSRC}/ngtcltk/ngappinit.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/demoapp/demoapp.tcl ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/tutorials/${doc} ${DOCSDIR}
. endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
