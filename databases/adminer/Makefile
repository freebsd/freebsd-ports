# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	adminer
PORTVERSION=	3.7.1
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/Adminer/Adminer%20${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Full-featured database management tool written in PHP

LICENSE=	APACHE20

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	mssql mysql odbc pgsql session pdo_sqlite
SUB_FILES=	pkg-message

NO_STAGE=	yes
do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
