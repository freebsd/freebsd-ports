# New ports collection makefile for:   pear-DB_DataObject
# Date created:        23 August 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	DB_DataObject
PORTVERSION=	1.7.2
CATEGORIES=	databases www pear

MAINTAINER=	antonio@php.net
COMMENT=	An SQL Builder, Object Interface to Database Tables

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes

CATEGORY=	DB
FILES=		DataObject.php DataObject/Cast.php DataObject/Error.php \
		DataObject/Generator.php DataObject/createTables.php

DOCS=		example.ini

LATEST_LINK=    pear-DB_DataObject
OPTIONS=        PEAR_VALIDATE "PEAR::Validate support" off

.include <bsd.port.pre.mk>

PHP_VERS=       ${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 420
BROKEN=         "You need PHP 4.2.0 or later to install PEAR::DB_DataObject"
.endif

.if defined(WITH_PEAR_VALIDATE)
BUILD_DEPENDS+= ${PEARDIR}/Validate.php:${PORTSDIR}/devel/pear-Validate
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
