PORTNAME=	phpminiadmin
DISTVERSION=	1.9.240801
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.php
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Lightweight alternative to phpMyAdmin
WWW=		https://phpminiadmin.sourceforge.net

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

USES=		cpe php:flavors
CPE_VENDOR=	${PORTNAME}_project
USE_PHP=	mysqli session

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${WWWDIR_REL}/phpminiadmin.php

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/phpminiadmin.php \
		${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
