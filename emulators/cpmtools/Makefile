# New ports collection makefile for:	cpm(1)
# Version required:	1.1
# Date created:		25 December 1994
# Whom:			joerg
#
# $Id: Makefile,v 1.7 1995/04/28 15:05:31 jkh Exp $
#

DISTNAME=	cpm-1.1
CATEGORIES+=	utils
MASTER_SITES=	ftp://freefall.cdrom.com/pub/FreeBSD/LOCAL_PORTS/
MAINTAINER=	joerg@FreeBSD.org

WRKSRC=		${WRKDIR}/cpm

#
# need our own build target to pass PREFIX down to the make command
#
do-build:
	@(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} all)


.include <bsd.port.mk>
