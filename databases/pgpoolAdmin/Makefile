# $FreeBSD$

PORTNAME=	pgpoolAdmin
PORTVERSION=	3.3.1
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/

MAINTAINER= 	ports@FreeBSD.org
COMMENT=	Web-based administration tool for pgpool-II

RUN_DEPENDS=	pgpool:${PORTSDIR}/databases/pgpool-II

USE_PHP=	mbstring pcre pgsql session
NO_BUILD=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-extract:
	${MV} ${WRKSRC}/conf/pgmgt.conf.php ${WRKSRC}/conf/pgmgt.conf.php.sample

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! -name *\.orig" )

.include <bsd.port.mk>
