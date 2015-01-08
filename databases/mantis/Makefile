# Created by: Sebastien Gioria <gioria@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mantis
PORTVERSION=	1.2.18
PORTREVISION=	0
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}bt/${PORTNAME}-stable/${PORTVERSION}
DISTNAME=	mantisbt-${PORTVERSION}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bug tracking system written in PHP

NO_BUILD=	yes
USE_PHP=	hash pcre session
USES=	pgsql

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}


do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
