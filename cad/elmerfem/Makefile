# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	elmerfem
PORTVERSION=	8.1.20160311
CATEGORIES=	cad science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ELMER FEM package

LICENSE=	GPLv2

LIB_DEPENDS=	libparpack.so:math/arpack-ng-mpich	\
		libmpich.so.8:net/mpich2

USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC
GH_TAGNAME=	dee8ceb

USES=		blaslapack:netlib cmake fortran gmake tcl

USE_LDCONFIG=	${PREFIX}/lib/elmersolver
ALL_TARGET=

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
	cd  ${STAGEDIR}${PREFIX}/bin	\
	&& ${LN} -sf ElmerSolver_mpi ${STAGEDIR}${PREFIX}/bin/ElmerSolver
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ElmerGrid

.if defined(MAINTAINER_MODE)
regression-test: install
	cd ${WRKSRC} && LD_LIBRARY_PATH=${PREFIX}/share/elmersolver/lib ${MAKE_CMD} 1dtest_Source
.endif

.include <bsd.port.post.mk>
