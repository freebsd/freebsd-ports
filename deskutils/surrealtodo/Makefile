# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	surrealtodo
PORTVERSION=	0.6.1.2
CATEGORIES=	deskutils
MASTER_SITES=	SF/surrealtodo/Surreal%20ToDo/
DISTNAME=	surrealtodo_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Surreal ToDo is an AJAX enabled web 2.0 list manager

BROKEN_powerpc64=	Does not build

USES=		zip
USE_PHP+=	mysql
USE_MYSQL=	yes
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}
IGNORE_WITH_PHP=	70

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=	pkg-message
PLIST_SUB=	OWNER="${WWWOWN}" GROUP="${WWWGRP}"

OPTIONS_DEFINE=	PGSQL APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE
LIGHTTPD_DESC=	Use Lighttpd webserver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOSTGRE}
USE_PHP+=	pgsql
.endif
.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22
.endif
.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:www/lighttpd
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${CP} -r ${WRKDIR}/${PORTNAME}_v${PORTVERSION}/* ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
