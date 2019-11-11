# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	elmerfem
PORTVERSION=	8.4
DISTVERSIONPREFIX=	release-
CATEGORIES=	cad science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite element software for multiphysical problems

LICENSE=	GPLv2

LIB_DEPENDS=	libparpack.so:math/arpack-ng \
		libmetis.so:math/metis \
		libmpich.so:net/mpich

USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC

USES=		blaslapack:netlib cmake fortran tcl

USE_LDCONFIG=	${PREFIX}/lib/elmersolver
ALL_TARGET=	# empty

CMAKE_ARGS=	-DELMER_FEM_REVISION:STRING=f6bfdc9

CMAKE_ARGS+=	-DHAVE_INTTYPES_H=ON
.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS_${ARCH}=	-fPIC
CXXFLAGS_${ARCH}= -fPIC
FCFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

LDFLAGS+=	-L${LOCALBASE}/lib
FCPPFLAGS+=	-ansi

post-patch:
	@${RM} -r ${WRKSRC}/elmergrid/src/metis-5.1.0
	@${REINPLACE_CMD} -e 's,"metis.*/metis\.h",<metis.h>,' \
		${WRKSRC}/elmergrid/src/femelmer.c

post-install:
	${LN} -sf ElmerSolver_mpi ${STAGEDIR}${PREFIX}/bin/ElmerSolver
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ElmerGrid

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.post.mk>
