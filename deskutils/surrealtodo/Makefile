# New ports collection makefile for:	surrealtodo
# Date created:				17 January 2011
# Whom:					jamrich.majo@gmail.com
#
# $FreeBSD$
#

PORTNAME=	surrealtodo
PORTVERSION=	0.6.1
CATEGORIES=	deskutils
MASTER_SITES=	SF/surrealtodo/Surreal%20ToDo/
DISTNAME=	surrealtodo-v${PORTVERSION}

MAINTAINER=	jamrich.majo@gmail.com
COMMENT=	Surreal ToDo is an AJAX enabled web 2.0 list manager

USE_ZIP=	yes
USE_PHP+=	mysql
USE_MYSQL=	yes
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=	pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

OPTIONS=	POSTGRE "Use PostgreSQL Database" off \
		APACHE "Use Apache webserver" on \
		LIGHTTPD "Use Lighttpd webserver" off

.include <bsd.port.options.mk>

.if defined(WITH_POSTGRE)
USE_PHP+=	pgsql
.endif
.if defined(WITH_APACHE)
USE_APACHE=	22
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/${PORTNAME}-v${PORTVERSION}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
