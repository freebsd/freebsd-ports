# New ports collection makefile for:	cpm(1)
# Version required:	1.1
# Date created:		25 December 1994
# Whom:			joerg
#
# $Id: Makefile,v 1.1.1.1 1994/12/28 11:53:41 joerg Exp $
#

DISTNAME=	cpm-1.1
WRKSRC=		${WRKDIR}/cpm

MAINTAINER=	joerg@FreeBSD.org
#
# need our own build target to pass PREFIX down to the make command
#
build:
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} all)


.include <bsd.port.mk>
