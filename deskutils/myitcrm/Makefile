# New ports collection makefile for:	myitcrm
# Date created:				9 January 2011
# Whom:					jamrich.majo@gmail.com
#
# $FreeBSD$
#

PORTNAME=	myitcrm
PORTVERSION=	0.2.9.1
CATEGORIES=	deskutils
MASTER_SITES=	SF/myitcrm/
DISTNAME=	MyITCRM-${PORTVERSION}

MAINTAINER=	jamrich.majo@gmail.com
COMMENT=	MYIT CRM is a CRM project designed for Computer Servicing and Repairs

USE_ZIP=	yes
USE_PHP+=	mysql
USE_MYSQL=	yes
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=	pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

OPTIONS=	APACHE "Use Apache webserver" on \
		LIGHTTPD "Use Lighttpd webserver" off

.include <bsd.port.options.mk>

.if defined(WITH_APACHE)
USE_APACHE=	22
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/${PORTNAME}-${PORTVERSION}/* ${WWWDIR}
	@${TOUCH} ${WWWDIR}/conf.php
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
