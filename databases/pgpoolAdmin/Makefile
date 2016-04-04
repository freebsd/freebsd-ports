# $FreeBSD$

PORTNAME=	pgpoolAdmin
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/

MAINTAINER= 	ports@FreeBSD.org
COMMENT=	Web-based administration tool for pgpool-II

LICENSE=	MIT

RUN_DEPENDS=	pgpool:databases/pgpool-II

USE_PHP=	mbstring pcre pgsql session
NO_BUILD=	yes
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-extract:
	${MV} ${WRKSRC}/conf/pgmgt.conf.php ${WRKSRC}/conf/pgmgt.conf.php.sample

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! -name *\.orig" )

.include <bsd.port.pre.mk>

.if ${PGSQL_DEFAULT} > 9.2
IGNORE=		you have PGSQL_DEFAULT set to ${PGSQL_DEFAULT} but pgpool-II needs 9.2 or less
.endif

.include <bsd.port.post.mk>
