# New ports collection makefile for:	phpcollab
# Date created:				4 Januar 2011
# Whom:					jamrich.majo@gmail.com
#
# $FreeBSD$
#

PORTNAME=	phpcollab
PORTVERSION=	2.5
CATEGORIES=	deskutils
MASTER_SITES=	SF/phpcollab/final/${PORTVERSION}/
DISTNAME=	phpcollab-${PORTVERSION}

MAINTAINER=	jamrich.majo@gmail.com
COMMENT=	PHPcollab is project management and collaboration over the internet

USE_ZIP=	yes
USE_PHP+=	mysql
USE_MYSQL=	yes
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=      pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

OPTIONS=	POSTGRE "Use PostgreSQL Database" off \
		APACHE "Use Apache webserver" on \
		LIGHTTPD "Use Lighttpd webserver" off

.include <bsd.port.options.mk>

.if defined(WITH_POSTGRE)
USE_PHP+=	pgsql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif
.if defined(WITH_APACHE)
USE_APACHE=	22
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/phpcollab/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
