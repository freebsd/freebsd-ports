# New ports collection makefile for:	gqlplus
# Date created:				06 November 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqlplus
PORTVERSION=	1.5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	leeym@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
