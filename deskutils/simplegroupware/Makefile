# New ports collection makefile for:	simplegroupware
# Date created:				7 January 2011
# Whom:					jamrich.majo@gmail.com
#
# $FreeBSD$
#

PORTNAME=	simplegroupware
PORTVERSION=	0.700
CATEGORIES=	deskutils
MASTER_SITES=	SF/simplgroup/${PORTNAME}/${PORTVERSION}/
DISTNAME=	SimpleGroupware_${PORTVERSION}

MAINTAINER=	jamrich.majo@gmail.com
COMMENT=	Simple Groupware is an open source enterprise application

USE_PHP+=	mysql
USE_MYSQL=	yes
USE_APACHE=	22
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=      pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/SimpleGroupware_${PORTVERSION}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
