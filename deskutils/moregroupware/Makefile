# New ports collection makefile for:	deskutils/moregroupware
# Date created:				December 30th 2003
# Whom:	      				Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	moregroupware
PORTVERSION=	0.7.4
PORTREVISION=	2
CATEGORIES=	deskutils www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	A web based GroupWare system

# php extensions
USE_PHP=	curl \
		gd \
		pcre \
		session \
		xml

WANT_PHP_MOD=	yes

OPTIONS=	ADDONS "install additional workgroup features (addons)" off \
		POSTGRESQL "use PostgreSQL instead of MySQL" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${LOCALBASE}/bin/psql:${PORTSDIR}/databases/postgresql74-server
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/mysql:${PORTSDIR}/databases/mysql50-server
.endif

.if defined (WITH_ADDONS)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-addons-${PORTVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	ADDONS=""
.else
PLIST_SUB+=	ADDONS="@comment "
.endif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:R}

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/www/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/moregroupware

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
