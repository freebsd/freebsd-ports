# Created by: Chao Shin <quakelee@cn.freebsd.org>
# $FreeBSD$

PORTNAME=	mdtest
PORTVERSION=	1.9.3
PORTREVISION=	7
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20latest/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filesystem metadata benchmark utility

LICENSE=	GPLv2

USES=		tar:tgz
NO_WRKSUBDIR=	yes

CFLAGS+=	-DDarwin

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTEXAMPLES=	*

OPTIONS_DEFINE=	OPENMPI EXAMPLES
OPENMPI_DESC=	Use Open MPI instead of MPICH2

OPENMPI_BUILD_DEPENDS=		${LOCALBASE}/mpi/openmpi/bin/mpicc:net/openmpi
OPENMPI_RUN_DEPENDS=		${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi
OPENMPI_VARS=			MPICC=${LOCALBASE}/mpi/openmpi/bin/mpicc

OPENMPI_BUILD_DEPENDS_OFF=	${LOCALBASE}/bin/mpicc:net/mpich2
OPENMPI_RUN_DEPENDS_OFF=	${LOCALBASE}/bin/mpirun:net/mpich2
OPENMPI_VARS_OFF=		MPICC=${LOCALBASE}/bin/mpicc

do-build:
	(cd ${WRKSRC} && ${MPICC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
