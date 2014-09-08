# Created by: Sebastien Gioria <gioria@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mantis
PORTVERSION=	1.2.17
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}bt/${PORTNAME}-stable/${PORTVERSION}
DISTNAME=	mantisbt-${PORTVERSION}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bug tracking system written in PHP

NO_BUILD=	yes
USE_PSQL=	yes
USE_PHP=	hash pcre session

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}/
	${MKDIR} ${STAGEDIR}${WWWDIR}/docbook/developers/en/build
	${MKDIR} ${STAGEDIR}${WWWDIR}/docbook/administration_guide/en/build
	${MKDIR} ${STAGEDIR}${WWWDIR}/docbook/adminguide/en/build

.include <bsd.port.mk>
