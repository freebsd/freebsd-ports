# Created by: Chao Shin <quakelee@cn.freebsd.org>
# $FreeBSD$

PORTNAME=	mdtest
PORTVERSION=	1.8.4
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20latest/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A filesystem metadata benchmark utility

LICENSE=	GPLv2

OPTIONS_DEFINE=	OPENMPI EXAMPLES
OPENMPI_DESC=	Use openmpi instead of mpich2

MAN1=		${PORTNAME}.1
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

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
	cd ${WRKSRC} && ${MPICC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
