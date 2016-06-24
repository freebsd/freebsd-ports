# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	imb
PORTVERSION=	3.0
PORTREVISION=	12
CATEGORIES=	benchmarks parallel
MASTER_SITES=	LOCAL/itetcu \
		http://cache-www.intel.com/cd/00/00/32/71/
DISTNAME=	327191_327191
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intel MPI Benchmark

WRKSRC=		${WRKDIR}/IMB_3.0/src/
USES=		dos2unix gmake
MAKEFILE=	make_mpich
# Intel hardcodes -O3 in make_mpich.  Replacing it with system defaults
# would make it impossible to compare benchmark results with other systems.
# By putting it here we make it easier for somebody to change it, if they
# _really_ want it.
CFLAGS=		-O3

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	CHECK_RESULTS DOCS OPENMPI

# Attention: -DCHECK results are not valid as real benchmark data! Don't
# forget to deactivate DCHECK and recompile in order to get proper results.
CHECK_RESULTS_DESC=	Check results (not valid as real benchmark data)
CHECK_RESULTS_CFLAGS=	-DCHECK

OPENMPI_BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
OPENMPI_RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi
OPENMPI_MAKE_ENV=	MPI_HOME=${LOCALBASE}/mpi/openmpi
OPENMPI_BUILD_DEPENDS_OFF=	${LOCALBASE}/bin/mpicc:net/mpich2
OPENMPI_RUN_DEPENDS_OFF=	${LOCALBASE}/bin/mpirun:net/mpich2
OPENMPI_MAKE_ENV_OFF=	MPI_HOME=${LOCALBASE}

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} IMB-EXT IMB-IO IMB-MPI1 \
		${STAGEDIR}${PREFIX}/bin)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/IMB_3.0/doc/IMB_ug-3.0.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/IMB_3.0/license/license.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/IMB_3.0/license/use-of-trademark-license.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
