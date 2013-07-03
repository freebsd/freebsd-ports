# Created by: Sebastien Gioria <gioria@FreeBSD.ORG>
# $FreeBSD$

PORTNAME=	mantis
PORTVERSION=	1.2.15
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}bt/${PORTNAME}-stable/${PORTVERSION}
DISTNAME=	mantisbt-${PORTVERSION}

MAINTAINER=	dan@langille.org
COMMENT=	A bug tracking system written in PHP

NO_BUILD=	yes
USE_PSQL=	yes
USE_PHP=	hash pcre session

SUB_FILES=	pkg-message

do-install:
	@${ECHO} "Installing in WWWDIR: ${WWWDIR}"
	${MKDIR} ${WWWDIR}/
	${CP} -R ${WRKSRC}/* ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
	${MKDIR} ${WWWDIR}/docbook/developers/en/build
	${MKDIR} ${WWWDIR}/docbook/administration_guide/en/build
	${MKDIR} ${WWWDIR}/docbook/adminguide/en/build

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
