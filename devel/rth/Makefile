# New ports collection makefile for:	rth
# Date created:		2006-06-06
# Whom:			Jan Siml <jsi@jules.de>
#
# $FreeBSD$
#

PORTNAME=	rth
PORTVERSION=	1.6.1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rth
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jsi@jules.de
COMMENT=	Web-based requirement, test and bugtracking system

NO_BUILD=	yes
USE_PHP=	mysql gd

SUB_LIST=	"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

WANT_PHP_WEB=	yes

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/rth"
	${MKDIR} ${PREFIX}/www/rth
	${MV} ${WRKSRC}/api/properties_inc.php ${WRKSRC}/api/properties_inc.php-dist
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/rth
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/rth
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
