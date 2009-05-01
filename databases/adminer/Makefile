# New ports collection makefile for:   phpMinAdmin
# Date created:			28 August 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phpminadmin
PORTVERSION=	1.10.0
CATEGORIES=	databases www
MASTER_SITES=	SF
DISTNAME=	phpMinAdmin-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A MySQL Management Tool Written in PHP

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	mysql session
SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
