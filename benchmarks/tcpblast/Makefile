# New ports collection makefile for:	tcpblast
# Date created:		22 August 1994
# Whom:			mr
#
# $FreeBSD$
#
# port's source files are in src dir in portball

PORTNAME=	tcpblast
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	benchmarks net ipv6
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Measures the throughput of a tcp connection

PLIST_FILES=	bin/tcpblast

WRKSRC=		${WRKDIR}/src

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} -RP ${.CURDIR}/src ${WRKDIR}

.include <bsd.port.mk>
