# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	adminer
PORTVERSION=	4.2.4
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	https://www.adminer.org/static/download/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}.php ${PORTNAME}-${PORTVERSION}-en.php \
		${PORTNAME}-${PORTVERSION}-mysql.php ${PORTNAME}-${PORTVERSION}-mysql-en.php
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Full-featured database management tool written in PHP

LICENSE=	APACHE20

USES=		zip
NO_BUILD=	yes
USE_PHP=	mysqli session
SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_SINGLE=		VERSION
OPTIONS_SINGLE_VERSION=	LITE FULL

OPTIONS_GROUP=		LT
OPTIONS_GROUP_LT=	ONLY_MYSQL NLS

LITE_DESC=		Lite version (only a simple index.php)
FULL_DESC=		Full version (adminer and editor)
ONLY_MYSQL_DESC=	Only MySQL support - ONLY IN LITE VERSION
NLS_DESC=		Native Language Support - ONLY IN LITE VERSION

OPTIONS_DEFAULT=	FULL
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFULL}
USE_PHP+=mssql odbc pgsql pdo_sqlite
.else
ADMINER_FILE=${PORTNAME}-${PORTVERSION}
.if ${PORT_OPTIONS:MONLY_MYSQL}
POSTFIX_MYSQL=-mysql
.endif
.if ${PORT_OPTIONS:MNLS}
POSTFIX_NLS=-en
.endif
POSTFIX=${POSTFIX_MYSQL}${POSTFIX_NLS}
.endif

do-install:
.if ${PORT_OPTIONS:MFULL}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
.else
	${MKDIR} ${STAGEDIR}${WWWDIR}/${PORTNAME}
	${CP} ${DISTDIR}/${ADMINER_FILE}${POSTFIX}.php ${STAGEDIR}${WWWDIR}/${PORTNAME}/index.php
.endif

.include <bsd.port.mk>
