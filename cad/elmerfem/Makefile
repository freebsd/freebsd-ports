# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	elmerfem
PORTVERSION=	8.2.20161026
PORTREVISION=	1
CATEGORIES=	cad science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ELMER FEM package

LICENSE=	GPLv2

LIB_DEPENDS=	libparpack.so:math/arpack-ng-mpich	\
		libmpich.so.8:net/mpich2

USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC
GH_TAGNAME=	5172e02

USES=		blaslapack:netlib cmake fortran gmake tcl

USE_LDCONFIG=	${PREFIX}/lib/elmersolver
ALL_TARGET=	# empty

.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS_${ARCH}=	-fPIC
CXXFLAGS_${ARCH}= -fPIC
FCFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

LDFLAGS+=	-L${LOCALBASE}/lib
FCPPFLAGS+=	-ansi

post-install:
	${LN} -sf ElmerSolver_mpi ${STAGEDIR}${PREFIX}/bin/ElmerSolver
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ElmerGrid

do-test:
	cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${PREFIX}/share/elmersolver/lib ${MAKE_CMD} 1dtest_Source

.include <bsd.port.post.mk>
