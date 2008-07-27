# New ports collection makefile for:   ampache
# Date created:                28 December 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	ampache
PORTVERSION=	3.4.2
CATEGORIES=	audio www
MASTER_SITES=	http://ampache.org/downloads/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A Web-based Audio file manager

USE_PHP=	mysql pcre session iconv
WANT_PHP_WEB=	yes

NO_BUILD=	yes
USE_GETTEXT=	yes

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME} \
		WWWDIR=${WWWDIR}

do-install:
	${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR})
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
