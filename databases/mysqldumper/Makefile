# Created by: Marek Holienka <marekholienka@gmail.com>
# $FreeBSD$

PORTNAME=	mysqldumper
PORTVERSION=	1.24.2
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/MySQLDumper/
DISTNAME=	MySQLDumper${PORTVERSION}

MAINTAINER=	marekholienka@gmail.com
COMMENT=	Tool for backing up MySQL databases

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBI>=1.48:${PORTSDIR}/databases/p5-DBI

USE_ZIP=	yes
USE_MYSQL=	yes
USES=		perl5
USE_PHP=	session mysql zlib ftp

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/msd${PORTVERSION}

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	${CP} -a ${WRKDIR}/msd${PORTVERSION}/ ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
