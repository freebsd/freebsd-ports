# New ports collection makefile for:	deskutils/moregroupware
# Date created:				December 30th 2003
# Whom:	      				Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	moregroupware
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	moregroupware
DISTNAME=	${PORTNAME}-core-${PORTVERSION}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES=	${PORTNAME}-core-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-docs-${PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	rob@debank.tv
COMMENT=	A web based GroupWare system

# php extensions
USE_PHP=	\
		curl \
		gd \
		pcre \
		session \
		xml
# uses apache , php4 port decides if it is apache 1 or 2
WANT_PHP_MOD=	yes

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${LOCALBASE}/bin/psql:${PORTSDIR}/databases/postgresql74-server
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/mysql:${PORTSDIR}/databases/mysql41-server
.endif

.if defined(WITH_MODULES)
DISTFILES+=	${PORTNAME}-modules-insecure-${PORTVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	MODULES=""
.else
PLIST_SUB+=	MODULES="@comment "
.endif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/moregroupware

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/www/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/moregroupware

.include <bsd.port.mk>
