# New ports collection makefile for:   adminer
# Date created:			11 July, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	adminer
PORTVERSION=	3.2.0
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/Adminer/Adminer%20${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A full-featured database management tool written in PHP

LICENSE=	ASL

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	mssql mysql odbc pgsql session sqlite
SUB_FILES=	pkg-message

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
