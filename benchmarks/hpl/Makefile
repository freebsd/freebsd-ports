PORTNAME=	hpl
DISTVERSION=	2.3
PORTREVISION=	5
CATEGORIES=	benchmarks
MASTER_SITES=	NETLIB/benchmark/hpl

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	High Performance Computing Linpack Benchmark
WWW=		https://www.netlib.org/benchmark/hpl/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/www/copyright.html

USES=		fortran
HPL_ARCH?=	FreeBSD_PIV_CBLAS
MAKE_ARGS=	arch=${HPL_ARCH}
ALL_TARGET=	build

OPTIONS_DEFINE=		DOCS
OPTIONS_RADIO=		BLAS MPI
OPTIONS_RADIO_BLAS=	ATLAS BLIS FLEXIBLAS NETLIB OPENBLAS
OPTIONS_RADIO_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	NETLIB MPICH
BLIS_DESC=		BLAS implementation from FLAME
FLEXIBLAS_DESC=		BLAS and LAPACK wrapper library

ATLAS_USES=		blaslapack:atlas
BLIS_USES=		blaslapack:blis
FLEXIBLAS_USES=		blaslapack:flexiblas
NETLIB_USES=		blaslapack:netlib
OPENBLAS_USES=		blaslapack:openblas

MPICH_USES=		mpi:mpich
OPENMPI_USES=		mpi:openmpi

CFLAGS+=	-fomit-frame-pointer -funroll-loops

pre-configure:
	${REINPLACE_CMD} -e 's|^TOPdir[ ]*=.*$$|TOPdir = ${WRKSRC}| ; \
		s|^MPdir[ ]*=.*$$|MPdir = ${LOCALBASE}| ; \
		s|^LAdir[ ]*=.*$$|LAdir = ${LOCALBASE}| ; \
		s|^CC[ ]*=.*$$|CC = ${CC}| ; \
		s|^CCFLAGS[ ]*=.*$$|CCFLAGS = $$\(HPL_DEFS\) ${CFLAGS}| ; \
		s|^LINKER[ ]*=.*$$|LINKER = ${FC}| ; \
		s|^LINKFLAGS[ ]*=\(.*\)$$|LINKFLAGS =\1 ${LDFLAGS}| ; \
		s|^ARCHIVER[ ]*=.*$$|ARCHIVER = ${AR}| ; \
		s|ARCH[ )]|_&|g ; \
		s|^HPL_OPTS[ ]*=.*$$|HPL_OPTS =| ; \
		s|^LAlib[ ]*=.*$$|LAlib = ${BLASLIB}| ; \
		s|^MPdir[ ]*=.*$$|MPdir = ${MPI_HOME}| ; \
		s|^MPinc[ ]*=.*$$|MPinc = ${MPI_CFLAGS}| ; \
		s|^MPlib[ ]*=.*$$|MPlib = ${MPI_LIBS}|' \
		${WRKSRC}/setup/Make.${HPL_ARCH}
	${REINPLACE_CMD} -e 's|HPL\.dat|${PREFIX}/etc/${PORTNAME}/&|' \
		${WRKSRC}/testing/ptest/HPL_pdinfo.c
	${CP} ${WRKSRC}/setup/Make.${HPL_ARCH} ${WRKSRC}/
	${REINPLACE_CMD} -e '/^build/s|$$| startup|' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${HPL_ARCH}/xhpl ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/${HPL_ARCH}/HPL.dat ${STAGEDIR}${ETCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/man3/*.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in BUGS COPYRIGHT HISTORY README TODO TUNING
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
