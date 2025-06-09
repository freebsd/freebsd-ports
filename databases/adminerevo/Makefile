PORTNAME=	adminerevo
DISTVERSION=	4.8.4
CATEGORIES=	databases www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	adminer-${DISTVERSION}
EXTRACT_SUFX=	.php
EXTRACT_ONLY=

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Database management in a single PHP file
WWW=		https://adminerevo.org \
		https://github.com/${PORTNAME}/${PORTNAME}

LICENSE=	APACHE20 GPLv3
LICENSE_COMB=	dual

DEPRECATED=		Abandoned upstream, repo archived Jan 24, 2025
EXPIRATION_DATE=	2025-09-08

USES=		php
USE_PHP=	session

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PHPVER="${PHP_VER}"

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${WWWDIR}/index.php

.include <bsd.port.mk>
