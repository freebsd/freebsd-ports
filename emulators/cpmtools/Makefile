# New ports collection makefile for:	cpm(1)
# Version required:	1.1
# Date created:		25 December 1994
# Whom:			joerg
#
# $Id: Makefile,v 1.2 1995/04/01 13:48:34 joerg Exp $
#

DISTNAME=	cpm-1.1

MAINTAINER=	joerg@FreeBSD.org

WRKSRC=		${WRKDIR}/cpm

#
# need our own build target to pass PREFIX down to the make command
#
build:
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} all)


.include <bsd.port.mk>
