PORTNAME=	IMB
DISTVERSIONPREFIX=	IMB-v
DISTVERSION=	2021.11
CATEGORIES=	benchmarks parallel

MAINTAINER=	laurent@FreeBSD.org
COMMENT=	Intel(R) MPI Benchmark
WWW=		https://software.intel.com/en-us/imb-user-guide

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/license.txt

NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	64-bit size_t assumed in various places

FLAVORS=		mpich openmpi
FLAVOR?=		${FLAVORS:[1]}
openmpi_PKGNAMESUFFIX=	-openmpi

USES=		gmake localbase mpi:${FLAVOR}
USE_CXXSTD=	c++14

USE_GITHUB=	yes
GH_ACCOUNT=	intel
GH_PROJECT=	mpi-benchmarks

MAKE_ENV=	MPI_HOME=${MPI_HOME}

# Intel hardcodes -O3 in make_mpich.  Replacing it with system defaults
# would make it impossible to compare benchmark results with other systems.
# By putting it here we make it easier for somebody to change it, if they
# _really_ want it.
OPT_CFLAGS=	-O3
CFLAGS+=	${OPT_CFLAGS} ${MPI_CFLAGS}
CXXFLAGS+=	-fopenmp
LDFLAGS+=	-Wl,-rpath,/lib ${MPI_LIBS} -fopenmp

CC=		${MPICC}
CXX=		${MPICXX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${FLAVOR}
BINARY_ALIAS=	make=${GMAKE}

PLIST_SUB=	FLAVOR=${FLAVOR}

OPTIONS_DEFINE=	CHECK_RESULTS DOCS

# Attention: -DCHECK results are not valid as real benchmark data! Don't
# forget to deactivate DCHECK and recompile in order to get proper results.
CHECK_RESULTS_DESC=	Check results (not valid as real benchmark data)
CHECK_RESULTS_CFLAGS=	-DCHECK

do-install:
	@for benchmark in ${WRKSRC}/IMB-*; do \
		${INSTALL_PROGRAM} $${benchmark} \
			${STAGEDIR}${PREFIX}/bin/$${benchmark##*/}-${FLAVOR}; \
	done

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe_IMB.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license/third-party-programs.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license/use-of-trademark-license.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
