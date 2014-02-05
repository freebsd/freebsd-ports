# Created by: spam@rm-rf.kiev.ua
# $FreeBSD$

PORTNAME=	phpminiadmin
DISTVERSION=	1.5.091221
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight alternative to phpMyAdmin

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	${WWWDIR_REL}/phpminiadmin.php
PLIST_DIRS=	${WWWDIR_REL}

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	mysql session pcre
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/phpminiadmin.php ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
