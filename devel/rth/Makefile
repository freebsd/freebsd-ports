# New ports collection makefile for:	rth
# Date created:		2006-06-06
# Whom:			Jan Siml <jsi@jules.de>
#
# $FreeBSD$
#

PORTNAME=	rth
PORTVERSION=	1.7.0
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/Release%20${PORTVERSION}/Release%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jsi@jules.de
COMMENT=	Web-based requirement, test and bugtracking system

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	mysql gd

SUB_LIST=	"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/rth"
	${MKDIR} ${PREFIX}/www/rth
	${MV} ${WRKSRC}/api/properties_inc.php ${WRKSRC}/api/properties_inc.php-dist
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/rth
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/rth
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
