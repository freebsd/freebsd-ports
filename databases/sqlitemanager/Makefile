# New ports collection makefile for:	sqlitemanager
# Date created:		2006-12-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	sqlitemanager
PORTVERSION=	1.2.0
CATEGORIES=	databases www
MASTER_SITES=	SF
DISTNAME=	SQLiteManager-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	A multilingual web based tool to manage SQLite database

NO_BUILD=	yes
USE_PHP=	sqlite
IGNORE_WITH_PHP=4

do-install:
	${MKDIR} ${PREFIX}/www/${PORTNAME}
	${CP} -R ${WRKSRC}/ ${PREFIX}/www/${PORTNAME}

.include <bsd.port.mk>
