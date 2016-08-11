# Created by: Jan Siml <jsi@jules.de>
# $FreeBSD$

PORTNAME=	rth
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/Release%20${PORTVERSION}/Release%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based requirement, test, and bugtracking system

BROKEN_powerpc64=	Does not build

USES=		zip
NO_BUILD=	yes
USE_PHP=	mysqli gd

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_LIST=	"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/rth"
	${MKDIR} ${STAGEDIR}${PREFIX}/www/rth
	${MV} ${WRKSRC}/api/properties_inc.php ${WRKSRC}/api/properties_inc.php.sample
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/www/rth

.include <bsd.port.mk>
