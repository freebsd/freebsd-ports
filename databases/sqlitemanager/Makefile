# New ports collection makefile for:	sqlitemanager
# Date created:		2006-12-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	sqlitemanager
PORTVERSION=	1.2.3
CATEGORIES=	databases www
MASTER_SITES=	SF
DISTNAME=	SQLiteManager-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	A multilingual web based tool to manage SQLite database

IGNORE_WITH_PHP=	4
NO_BUILD=	yes
PLIST_SUB+=	WWWDIR_REL="${WWWDIR_REL}"
USE_PHP=	sqlite

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/ ${WWWDIR}

.include <bsd.port.mk>
