# $FreeBSD$

PORTNAME=	pgpoolAdmin
PORTVERSION=	3.0.1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2805/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Web-based administration tool for pgpool-II

RUN_DEPENDS=	pgpool:${PORTSDIR}/databases/pgpool-II

USE_PHP=	mbstring pcre pgsql session
NO_BUILD=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

NO_STAGE=	yes
post-extract:
	${MV} ${WRKSRC}/conf/pgmgt.conf.php ${WRKSRC}/conf/pgmgt.conf.php.sample

pre-install:
	${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}

do-install:
	${MKDIR} ${WWWDIR}/templates_c
	${CP} -R ${WRKSRC}/* ${WWWDIR}/
	${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/templates_c ${WWWDIR}/conf/pgmgt.conf.php.sample

.include <bsd.port.mk>
