# New ports collection makefile for:	tcpblast
# Version required:	<self contained>
# Date created:		22 August 1994
# Whom:			mr
#
# $FreeBSD$
#

DISTNAME=	tcpblast
PKGNAME=	tcpblast-1.0
CATEGORIES=	benchmarks net
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org

NO_CHECKSUM=	"port's source files are part of this portball"
WRKSRC=		${WRKDIR}/src

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} -RP ${.CURDIR}/src ${WRKDIR}

.include <bsd.port.mk>
