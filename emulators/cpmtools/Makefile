# New ports collection makefile for:	cpm(1)
# Version required:	1.1
# Date created:		25 December 1994
# Whom:			joerg
#
# $Id: Makefile,v 1.10 1995/07/12 22:48:51 asami Exp $
#

DISTNAME=	cpm-1.1
PKGNAME=	cpmtools-1.1
CATEGORIES+=	emulation
MASTER_SITES=	ftp://freefall.cdrom.com/pub/FreeBSD/LOCAL_PORTS/
MAINTAINER=	joerg@FreeBSD.org

WRKSRC=		${WRKDIR}/cpm

#
# need our own build target to pass PREFIX down to the make command
#
do-build:
	@(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} all)


.include <bsd.port.mk>
