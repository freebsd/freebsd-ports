# New ports collection makefile for:   mantis
# Date created:        6 December 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	mantis
PORTVERSION=	0.18.0
CATEGORIES=	databases www
MASTER_SITES=	http://switch.dl.sourceforge.net/sourceforge/mantisbt/ \
		http://umn.dl.sourceforge.net/sourceforge/mantisbt/ \
		http://keihanna.dl.sourceforge.net/sourceforge/mantisbt/ \
		http://flow.dl.sourceforge.net/sourceforge/mantisbt/

MAINTAINER=	gioria@FreeBSD.org
COMMENT=	A bug tracking system written in PHP

RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/lang/php4

NO_BUILD=	yes
USE_MYSQL=	yes
USE_APACHE=	yes

do-install:
	${ECHO} "Installing in ${PREFIX}/www/data/mantis"
	${MKDIR} ${PREFIX}/www/data/mantis
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/data/mantis
	${MV} ${PREFIX}/www/data/mantis/config_inc.php.sample ${PREFIX}/www/data/mantis/config_inc.php
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/data/mantis

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
