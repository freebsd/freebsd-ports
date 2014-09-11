# Created by: Jan Siml <jsi@jules.de>
# $FreeBSD$

PORTNAME=	truc
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TRUC%20Testing%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jsi@jules.de
COMMENT=	Web-based tool for requirement and use case tracking

NO_BUILD=	yes
USE_PHP=	mysql gd

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_LIST=	"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

WANT_PHP_WEB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/truc
#	${MV} ${WRKSRC}/config_inc.php ${WRKSRC}/config_inc.php-dist
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/www/truc

.include <bsd.port.mk>
