# Created by: Petr Macek <pm@kostax.cz>
# $FreeBSD$

PORTNAME=	mywwwatcher
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	http://www.the.cz/mywwwatcher/files/
DISTNAME=	mywwwatcher-${PORTVERSION}

MAINTAINER=	pm@kostax.cz
COMMENT=	Simple web-based MySQL client + tools (dump, import, scheme, ...)

DEPRECATED=	PHP 5.4 EOL reached
EXPIRATION_DATE=	2016-01-15

WRKSRC=		${WRKDIR}/mywwwatcher

WANT_PHP_WEB=		yes
DEFAULT_PHP_VER=	5
USE_PHP=		pcre session mysql
PLIST_SUB=		WWWGRP="${WWWGRP}"

NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${CP} -Rp ${WRKSRC}/* ${STAGEDIR}${WWWDIR}
	@${CHMOD} 775 ${STAGEDIR}${WWWDIR}/ini
	@${CHMOD} 775 ${STAGEDIR}${WWWDIR}/query_archive

.include <bsd.port.mk>
