# New ports collection makefile for:	gqlplus
# Date created:				06 November 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqlplus
PORTVERSION=	1.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	SQL*PLUS with commandline editing, history, and name completion

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
