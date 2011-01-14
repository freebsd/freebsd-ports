# New ports collection makefile for:	mysqldumper
# Date created:				8 January 2011
# Whom:		Marek Holienka	<marekholienka@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mysqldumper
PORTVERSION=	1.24.2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/MySQLDumper/
DISTNAME=	MySQLDumper${PORTVERSION}

MAINTAINER=	marekholienka@gmail.com
COMMENT=	MySQLDumper is tool for backing up MySQL databases

RUN_DEPENDS=	p5-DBI>=1.48:${PORTSDIR}/databases/p5-DBI \

OPTIONS=	APACHE "Enable Apache Support" on \
		LIGHTTPD "Enable Lighttpd Support" off

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/msd${PORTVERSION}
USE_PHP=	session mysql zlib ftp
USE_MYSQL=	yes
USE_PERL5=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

.include <bsd.port.options.mk>

.if defined(WITH_APACHE)
USE_APACHE=	1.3+
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/msd${PORTVERSION}/ ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
