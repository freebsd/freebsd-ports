# New ports collection makefile for:   mantis
# Date created:        6 December 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	mantis
PORTVERSION=	0.18.2
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
	${ECHO} "Installing in ${PREFIX}/www/data/mantis"
	${MKDIR} ${PREFIX}/www/data/mantis
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/data/mantis
	${MV} ${PREFIX}/www/data/mantis/config_inc.php.sample ${PREFIX}/www/data/mantis/config_inc.php
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/data/mantis

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
