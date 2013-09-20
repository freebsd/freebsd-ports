# Created by: mr
# $FreeBSD$

PORTNAME=	tcpblast
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	benchmarks net ipv6
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Measures the throughput of a TCP connection

PLIST_FILES=	bin/tcpblast

WRKSRC=		${WRKDIR}/src

NO_STAGE=	yes
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} -RP ${.CURDIR}/src ${WRKDIR}

.include <bsd.port.mk>
