# New ports collection makefile for:	deskutils/moregroupware
# Date created:				December 30th 2003
# Whom:	      				Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	moregroupware
PORTVERSION=	0.7.1
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

BROKEN=		Checksum mismatch

.if defined(WITH_APACHE2)
RUN_DEPENDS=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
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
