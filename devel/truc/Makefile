# New ports collection makefile for:	truc
# Date created:		2007-03-10
# Whom:			Jan Siml <jsi@jules.de>
#
# $FreeBSD$
#

PORTNAME=	truc
PORTVERSION=	0.12.0
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TRUC%20Testing%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jsi@jules.de
COMMENT=	Web-based tool for requirement and use case tracking

NO_BUILD=	yes
USE_PHP=	mysql gd

SUB_LIST=	"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

WANT_PHP_WEB=	yes

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/truc"
	${MKDIR} ${PREFIX}/www/truc
#	${MV} ${WRKSRC}/config_inc.php ${WRKSRC}/config_inc.php-dist
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/truc
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/truc
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
