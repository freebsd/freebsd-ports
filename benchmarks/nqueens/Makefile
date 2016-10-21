# Created by: NAKAJI Hiroyuki <nakaji@jp.freebsd.org>
# $FreeBSD$

PORTNAME=	nqueens
PORTVERSION=	1.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.arch.cs.titech.ac.jp/~kise/nq/package/
DISTNAME=	qn24b-version${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	N-queens benchmark

WRKSRC=		${WRKDIR}/version${PORTVERSION}

OPTIONS_DEFINE=	MPI STATIC OPTIMIZED_CFLAGS
MPI_DESC=	Build distributed MPI version
STATIC_DESC=	Link resulting binaries statically

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -pipe -s -ffast-math -funroll-loops -fomit-frame-pointer -fexpensive-optimizations
.endif
.if ${PORT_OPTIONS:MSTATIC}
CFLAGS+=	-static
.endif

PROGS=		qn24b_base

.if ${PORT_OPTIONS:MMPI}
MPICC?=		${LOCALBASE}/mpich/bin/mpicc
BUILD_DEPENDS=	${MPICC}:net/mpich
PROGS+=		qn24b_mpi
.endif

post-extract:
	@${RM} ${WRKSRC}/qn24b_base

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o qn24b_base base/queens.c
do-build-MPI-on:
	cd ${WRKSRC} && \
	${MPICC} ${CFLAGS} -o qn24b_mpi mpi/main.c

PLIST_FILES=	${PROGS:S/^/bin\//}

do-install:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
