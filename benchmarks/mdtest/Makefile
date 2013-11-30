# Created by: Chao Shin <quakelee@cn.freebsd.org>
# $FreeBSD$

PORTNAME=	mdtest
PORTVERSION=	1.9.2
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20latest/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filesystem metadata benchmark utility

LICENSE=	GPLv2

OPTIONS_DEFINE=	OPENMPI EXAMPLES
OPENMPI_DESC=	Use Open MPI instead of MPICH2

PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/mdtest.1.gz

NO_WRKSUBDIR=	yes
CFLAGS+=	-DDarwin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
MPICC=		${LOCALBASE}/mpi/openmpi/bin/mpicc
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:${PORTSDIR}/net/mpich2
MPICC=		${LOCALBASE}/bin/mpicc
.endif

do-build:
	(cd ${WRKSRC} && ${MPICC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c -lm)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/scripts && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
