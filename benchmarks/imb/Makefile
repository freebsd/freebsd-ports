PORTNAME=	IMB
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.7
PORTREVISION=	1
CATEGORIES=	benchmarks parallel
MASTER_SITES=	https://github.com/intel/mpi-benchmarks/archive/refs/tags/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intel MPI Benchmark
WWW=		https://software.intel.com/en-us/imb-user-guide

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/license.txt

#USE_GITHUB=	yes
#GH_ACCOUNT=	intel
#GH_PROJECT=	mpi-benchmarks

USES=		gmake localbase
USE_CXXSTD=	c++14

BINARY_ALIAS=	make=${GMAKE}

WRKSRC=		${WRKDIR}/mpi-benchmarks-${DISTNAME}

# Intel hardcodes -O3 in make_mpich.  Replacing it with system defaults
# would make it impossible to compare benchmark results with other systems.
# By putting it here we make it easier for somebody to change it, if they
# _really_ want it.
OPT_CFLAGS=	-O3
CC=		${MPICC}
CXX=		${MPICXX}
CFLAGS+=	${OPT_CFLAGS} ${MPI_CFLAGS}
LDFLAGS+=	${MPI_LIBS}
MAKE_ENV=	MPI_HOME=${MPI_HOME}

OPTIONS_DEFINE=		CHECK_RESULTS DOCS
OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH

# Attention: -DCHECK results are not valid as real benchmark data! Don't
# forget to deactivate DCHECK and recompile in order to get proper results.
CHECK_RESULTS_DESC=	Check results (not valid as real benchmark data)
CHECK_RESULTS_CFLAGS=	-DCHECK

MPICH_USES=	mpi:mpich
OPENMPI_USES=	mpi:openmpi

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} IMB-* ${STAGEDIR}${PREFIX}/bin)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe_IMB.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license/third-party-programs.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license/use-of-trademark-license.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
