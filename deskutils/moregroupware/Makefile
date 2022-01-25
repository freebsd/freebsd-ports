# Created by: Rob Evers <rob@debank.tv>

PORTNAME=	moregroupware
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	deskutils www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Web based GroupWare system

USES=		gettext php:mod
WANT_PGSQL=	server
# php extensions
USE_PHP=	curl gd pcre session xml

SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=		ADDONS NLS
OPTIONS_DEFAULT=	MYSQL
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_SUB=		yes

ADDONS_DESC=	install additional workgroup features (addons)

ADDONS_DISTFILES=	${PORTNAME}-addons-${PORTVERSION}${EXTRACT_SUFX}
MYSQL_USES=		mysql:server
NLS_USES=		gettext
PGSQL_USES=		pgsql

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
