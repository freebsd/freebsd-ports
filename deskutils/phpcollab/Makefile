# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	phpcollab
PORTVERSION=	2.5
CATEGORIES=	deskutils
MASTER_SITES=	SF/phpcollab/final/${PORTVERSION}/
DISTNAME=	phpcollab-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
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

OPTIONS_DEFINE=	PGSQL APACHE LIGHTTPD
LIGHTTPD_DESC=	Use Lighttpd webserver

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif
.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22
.endif
.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/phpcollab/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
