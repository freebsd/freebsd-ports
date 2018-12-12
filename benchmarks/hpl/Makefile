# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hpl
DISTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	NETLIB/benchmark/hpl

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	High Performance Computing Linpack Benchmark

LIB_DEPENDS=	libblas.so:math/blas \
		libmpich.so:net/mpich

USES=		fortran
USE_LDCONFIG=	yes
HPL_ARCH?=	FreeBSD_PIV_CBLAS
MAKE_ARGS=	arch=${HPL_ARCH}
ALL_TARGET=	build

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^TOPdir[ ]*=.*$$|TOPdir = ${WRKSRC}| ; \
		s|^MPdir[ ]*=.*$$|MPdir = ${LOCALBASE}| ; \
		s|^LAdir[ ]*=.*$$|LAdir = ${LOCALBASE}| ; \
		s|^CC[ ]*=.*$$|CC = ${CC}| ; \
		s|^CCFLAGS[ ]*=.*$$|CCFLAGS = $$\(HPL_DEFS\) ${CFLAGS} -fomit-frame-pointer -funroll-loops| ; \
		s|^LINKER[ ]*=.*$$|LINKER = ${FC}| ; \
		s|^ARCHIVER[ ]*=.*$$|ARCHIVER = ${AR}| ; \
		s|ARCH[ )]|_&|g ; \
		s|^HPL_OPTS[ ]*=.*$$|HPL_OPTS =| ; \
		s|^LAlib[ ]*=.*$$|LAlib = $$\(LAdir\)/lib/libblas.a| ; \
		s|libmpich.a|libmpich.so -lpthread| ; \
		s|libpmpich.a|libmpl.so -lpthread|' \
		${WRKSRC}/setup/Make.${HPL_ARCH}
	@${REINPLACE_CMD} -e 's|HPL\.dat|${PREFIX}/etc/${PORTNAME}/&|' \
		${WRKSRC}/testing/ptest/HPL_pdinfo.c
	@${CP} ${WRKSRC}/setup/Make.${HPL_ARCH} ${WRKSRC}/
	@${REINPLACE_CMD} -e '/^build/s|$$| startup|' ${WRKSRC}/Makefile

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
