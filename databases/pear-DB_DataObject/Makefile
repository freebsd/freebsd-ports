# New ports collection makefile for:   pear-DB_DataObject
# Date created:        23 August 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	DB_DataObject
PORTVERSION= 	1.7.1
CATEGORIES=	databases www pear

MAINTAINER=	antonio@php.net
COMMENT=	An SQL Builder, Object Interface to Database Tables

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	DB
FILES=		DataObject.php DataObject/Cast.php DataObject/Error.php \
		DataObject/Generator.php DataObject/createTables.php

DOCS=		example.ini

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
