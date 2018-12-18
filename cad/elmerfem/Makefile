# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	elmerfem
PORTVERSION=	8.3.20170524
PORTREVISION=	4
CATEGORIES=	cad science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ELMER FEM package

LICENSE=	GPLv2

BROKEN=		fails to build

LIB_DEPENDS=	libparpack.so:math/arpack-ng \
		libmpich.so:net/mpich

USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC
GH_TAGNAME=	release-8.3

USES=		blaslapack:netlib cmake:outsource fortran gmake tcl

USE_LDCONFIG=	${PREFIX}/lib/elmersolver
ALL_TARGET=	# empty

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

post-install:
	${LN} -sf ElmerSolver_mpi ${STAGEDIR}${PREFIX}/bin/ElmerSolver
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ElmerGrid

do-test:
	cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${PREFIX}/share/elmersolver/lib ${MAKE_CMD} 1dtest_Source

.include <bsd.port.post.mk>
