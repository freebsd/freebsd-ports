# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	sqlitemanager
PORTVERSION=	1.2.4
CATEGORIES=	databases www
MASTER_SITES=	SF
DISTNAME=	SQliteManager-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multilingual web based tool to manage SQLite database

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

WRKSRC=		${WRKDIR}/SQLiteManager-${PORTVERSION}
USES=		dos2unix
NO_BUILD=	yes
PLIST_SUB+=	WWWDIR_REL="${WWWDIR_REL}"
USE_PHP=	sqlite${PHP_VER:S/^53$$//:C/^.+$$/3/}
EXTRACT_AFTER_ARGS=--exclude TODO

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -Rp ${WRKSRC}/ ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
