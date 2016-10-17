# Created by: spam@rm-rf.kiev.ua
# $FreeBSD$

PORTNAME=	phpminiadmin
PORTVERSION=	1.9.160630
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.php
DIST_SUBDIR=	${PKGNAME}
EXTRACT_ONLY=

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Lightweight alternative to phpMyAdmin

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		php
USE_PHP=	mysqli pcre session
NO_ARCH=	yes

PLIST_FILES=	${WWWDIR_REL}/phpminiadmin.php

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/phpminiadmin.php \
		${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
