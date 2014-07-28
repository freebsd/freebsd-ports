# Created by: Marek Holienka <marekholienka@gmail.com>
# $FreeBSD$

PORTNAME=	mysqldumper
PORTVERSION=	1.24.2
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/MySQLDumper/
DISTNAME=	MySQLDumper${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for backing up MySQL databases

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBI>=1.48:${PORTSDIR}/databases/p5-DBI

USE_MYSQL=	yes
USES=		perl5 zip
USE_PHP=	session mysql zlib ftp

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/msd${PORTVERSION}

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKDIR}/msd${PORTVERSION}/ ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
