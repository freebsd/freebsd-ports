# New ports collection makefile for:	tcpblast
# Version required:	<self contained>
# Date created:		22 August 1994
# Whom:			mr
#
# $Id: Makefile,v 1.11 1996/11/20 01:59:27 obrien Exp $
#

DISTNAME=	tcpblast
PKGNAME=	tcpblast-1.0
CATEGORIES=	net benchmarks
DISTFILES=	# empty

WRKSRC=		${WRKDIR}/src

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${CP} -RP ${.CURDIR}/src ${WRKDIR}

.include <bsd.port.mk>
