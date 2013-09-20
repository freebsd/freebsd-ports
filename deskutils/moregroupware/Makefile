# Created by: Rob Evers <rob@debank.tv>
# $FreeBSD$

PORTNAME=	moregroupware
PORTVERSION=	0.7.4
PORTREVISION=	3
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

OPTIONS_DEFINE=	ADDONS PGSQL NLS
ADDONS_DESC=	install additional workgroup features (addons)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${LOCALBASE}/bin/psql:${PORTSDIR}/databases/postgresql74-server
.else
USE_MYSQL=	server
.endif

.if ${PORT_OPTIONS:MADDONS}
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

.include <bsd.port.mk>
