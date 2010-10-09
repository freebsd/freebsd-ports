# New ports collection makefile for:   mantis
# Date created:        6 December 2002
# Whom:                Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	mantis
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}bt/${PORTNAME}-stable/${PORTVERSION}
DISTNAME=	mantisbt-${PORTVERSION}

MAINTAINER=	dan@langille.org
COMMENT=	A bug tracking system written in PHP

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	hash pcre session

SUB_FILES=	pkg-message

do-install:
	@${ECHO} "Installing in WWWDIR: ${WWWDIR}"
	${MKDIR} ${WWWDIR}/
	${CP} -R ${WRKSRC}/* ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
