# New ports collection makefile for:	cpm(1)
# Date created:		25 December 1994
# Whom:			joerg
#
# $FreeBSD$
#

PORTNAME=	cpmtools
PORTVERSION=	1.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	joerg
DISTNAME=	cpm-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Utility to transfer files from/to CP/M (R) diskettes

WRKSRC=		${WRKDIR}/cpm
MAN1=		cpm.1

#
# need our own build target to pass PREFIX down to the make command
#
do-build:
	@(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} all)

.include <bsd.port.mk>
