# New ports collection makefile for:	mdtest
# Date created:		2007-4-20
# Whom:			Chao Shin <quakelee@cn.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mdtest
PORTVERSION=	1.7.1
PORTREVISION=	4
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.llnl.gov/icc/lc/siop/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A filesystem metadata benchmark utility

PLIST_FILES=	bin/mdtest

OPTIONS=	OPENMPI "Use openmpi instead of mpich2" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPENMPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:${PORTSDIR}/net/openmpi
MPICC=		${LOCALBASE}/mpi/openmpi/bin/mpicc
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/lib/libmpich.so:${PORTSDIR}/net/mpich2
MPICC=		${LOCALBASE}/bin/mpicc
.endif

USE_GMAKE=	yes
ALL_TARGET=	mdtest

post-patch:
	@${REINPLACE_CMD} -e 's|%%MPICC%%|${MPICC}|' ${WRKSRC}/${MAKEFILE}

do-install:
	${STRIP_CMD} ${WRKSRC}/mdtest
	${INSTALL_PROGRAM} ${WRKSRC}/mdtest ${PREFIX}/bin

.include <bsd.port.post.mk>
