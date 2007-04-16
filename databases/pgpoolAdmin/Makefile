# New ports collection makefile for:	pgpoolAdmin
# Date created:				Apr 10, 2007
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pgpoolAdmin
PORTVERSION=	1.0.0
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1068/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Web-based administration tool for pgpool-II

RUN_DEPENDS=	pgpool:${PORTSDIR}/databases/pgpool-II

USE_APACHE=	1.3+
USE_PHP=	mbstring pcre pgsql session
NO_BUILD=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-extract:
	${MV} ${WRKSRC}/conf/pgmgt.conf.php ${WRKSRC}/conf/pgmgt.conf.php.sample

pre-install:
	${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}/
	${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/templates_c ${WWWDIR}/conf/pgmgt.conf.php.sample

.include <bsd.port.mk>
