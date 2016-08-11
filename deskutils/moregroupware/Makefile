# Created by: Rob Evers <rob@debank.tv>
# $FreeBSD$

PORTNAME=	moregroupware
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	deskutils www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Web based GroupWare system

# php extensions
USE_PHP=	curl \
		gd \
		pcre \
		session \
		xml

USES=	gettext

WANT_PHP_MOD=	yes

OPTIONS_DEFINE=	ADDONS NLS
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	PGSQL MYSQL
OPTIONS_DEFAULT=	MYSQL
ADDONS_DESC=	install additional workgroup features (addons)
OPTIONS_SUB=	yes

NLS_USES=		gettext
PGSQL_USES=	pgsql
WANT_PGSQL=	server
MYSQL_USE=	MYSQL=server

ADDONS_DISTFILES=	${PORTNAME}-addons-${PORTVERSION}${EXTRACT_SUFX}
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
