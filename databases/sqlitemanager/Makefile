# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	sqlitemanager
PORTVERSION=	1.2.3
CATEGORIES=	databases www
MASTER_SITES=	SF
DISTNAME=	SQLiteManager-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multilingual web based tool to manage SQLite database

DEPRECATED=	requires php53, security EOL reached 14 Aug 2014
EXPIRATION_DATE=	2015-04-15

IGNORE_WITH_PHP=5 55 56
NO_BUILD=	yes
PLIST_SUB+=	WWWDIR_REL="${WWWDIR_REL}"
USE_PHP=	sqlite

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
