# New ports collection makefile for:	gqlplus
# Date created:				06 November 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqlplus
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	SQL*PLUS with commandline editing, history, and name completion

MAKEFILE=	makefile
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
