# New ports collection makefile for:   mantis
# Date created:        6 December 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	mantis
PORTVERSION=	1.0.0a2
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mantisbt

MAINTAINER=	gioria@FreeBSD.org
COMMENT=	A bug tracking system written in PHP

NO_BUILD=	yes
USE_MYSQL=	yes
USE_APACHE=	yes
USE_PHP=	yes

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/mantis"
	${MKDIR} ${PREFIX}/www/mantis
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/mantis
	${MV} ${PREFIX}/www/mantis/config_inc.php.sample ${PREFIX}/www/mantis/config_inc.php
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/mantis

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
