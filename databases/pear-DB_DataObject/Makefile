# New ports collection makefile for:   pear-DB_DataObject
# Date created:        23 August 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	DB_DataObject
PORTVERSION=	1.7.10
CATEGORIES=	databases pear

MAINTAINER=	antonio@php.net
COMMENT=	An SQL Builder, Object Interface to Database Tables

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

CATEGORY=	DB
FILES=		DataObject.php DataObject/Cast.php DataObject/Generator.php \
		DataObject/createTables.php DataObject/Error.php
DOCS=		example.ini

LATEST_LINK=	pear-DB_DataObject
OPTIONS=	PEAR_VALIDATE "PEAR::Validate support" off

post-patch:
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/DataObject.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_VALIDATE)
RUN_DEPENDS+=	${PEARDIR}/Validate.php:${PORTSDIR}/devel/pear-Validate
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
