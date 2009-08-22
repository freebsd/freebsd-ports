# New ports collection makefile for:   phpminiadmin
# Date created:			07 March 2007
# Whom:					spam@rm-rf.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	phpminiadmin
DISTVERSION=	1.4.080217
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Lightweight alternative to phpMyAdmin

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

MINIADMDIR=	www/${PORTNAME}
PLIST_FILES=	${MINIADMDIR}/phpminiadmin.php
PLIST_DIRS=	${MINIADMDIR}

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	mysql session pcre
.endif

do-install:
	${MKDIR} ${PREFIX}/${MINIADMDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/phpminiadmin.php ${PREFIX}/${MINIADMDIR}/

.include <bsd.port.mk>
