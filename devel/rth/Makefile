PORTNAME=	rth
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/Release%20${PORTVERSION}/Release%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based requirement, test, and bugtracking system
WWW=		https://sourceforge.net/projects/rth/

DEPRECATED=	Abandonware, Unmaintained upstream as of 2013
EXPIRATION_DATE=2024-09-30

USES=		php:web zip
NO_BUILD=	yes
USE_PHP=	mysqli gd

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_LIST=	"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/rth"
	${MKDIR} ${STAGEDIR}${PREFIX}/www/rth
	${MV} ${WRKSRC}/api/properties_inc.php ${WRKSRC}/api/properties_inc.php.sample
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/www/rth

.include <bsd.port.mk>
