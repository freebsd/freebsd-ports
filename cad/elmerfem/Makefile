# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	elmerfem
PORTVERSION=	7.0.20141202
CATEGORIES=	cad science

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	ELMER FEM package

LICENSE=	GPLv2

LIB_DEPENDS=	liblapack.so:${PORTSDIR}/math/lapack		\
		libparpack.so:${PORTSDIR}/math/arpack-ng-mpich	\
		libmpich.so.8:${PORTSDIR}/net/mpich2

USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC
GH_TAGNAME=	0300707

USES=		cmake fortran gmake tcl

USE_LDCONFIG=	yes
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
