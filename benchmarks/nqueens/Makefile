# New ports collection makefile for:	N-Queens
# Date Created:				2 March 2005
# Whom:					NAKAJI Hiroyuki <nakaji@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	nqueens
PORTVERSION=	1.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.arch.cs.titech.ac.jp/~kise/nq/package/
DISTNAME=	qn24b-version${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	N-queens benchmark

WRKSRC=		${WRKDIR}/version${PORTVERSION}

OPTIONS=	MPI "Build distributed MPI version" off \
		STATIC "Link resulting binaries statically" off \
		OPTIMIZED_CFLAGS "Enable extra optimization options" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O9 -pipe -s -ffast-math -funroll-loops -fomit-frame-pointer -fexpensive-optimizations
.endif
.if defined(WITH_STATIC)
CFLAGS+=	-static
.endif

PROGS=		qn24b_base

.if defined(WITH_MPI)
MPICC?=		${LOCALBASE}/mpich/bin/mpicc
BUILD_DEPENDS=	${MPICC}:${PORTSDIR}/net/mpich
PROGS+=		qn24b_mpi
.endif

post-extract:
	@${RM} -f ${WRKSRC}/qn24b_base

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o qn24b_base base/queens.c
.if defined(WITH_MPI)
	cd ${WRKSRC} && \
	${MPICC} ${CFLAGS} -o qn24b_mpi mpi/main.c
.endif

PLIST_FILES=	${PROGS:S/^/bin\//}

do-install:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${PREFIX}/bin/
.endfor

.include <bsd.port.post.mk>
