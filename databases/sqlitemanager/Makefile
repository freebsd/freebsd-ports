# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	sqlitemanager
PORTVERSION=	1.2.3
CATEGORIES=	databases www
MASTER_SITES=	SF
DISTNAME=	SQLiteManager-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	A multilingual web based tool to manage SQLite database

DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
NO_BUILD=	yes
PLIST_SUB+=	WWWDIR_REL="${WWWDIR_REL}"
USE_PHP=	sqlite

NO_STAGE=	yes
do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/ ${WWWDIR}

.include <bsd.port.mk>
