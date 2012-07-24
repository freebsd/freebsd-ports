# New ports collection makefile for:   	mywwwatcher
# Date created:				10 January 2007
# Whom:					Petr Macek <pm@kostax.cz>
#
# $FreeBSD$
#

PORTNAME=	mywwwatcher
PORTVERSION=	3.2
CATEGORIES=	databases www
MASTER_SITES=	http://www.the.cz/mywwwatcher/files/
DISTNAME=	mywwwatcher-${PORTVERSION}

MAINTAINER=	pm@kostax.cz
COMMENT=	Simple web-based MySQL client + tools (dump, import, scheme, ...)

WRKSRC=		${WRKDIR}/mywwwatcher

WANT_PHP_WEB=		yes
DEFAULT_PHP_VER=	5
USE_PHP=		pcre session mysql
IGNORE_WITH_PHP=	3

NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -Rp ${WRKSRC}/* ${WWWDIR}
	@${CHGRP} -R ${WWWGRP} ${WWWDIR}
	@${CHMOD} 775 ${WWWDIR}/ini
	@${CHMOD} 775 ${WWWDIR}/query_archive
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
