# New ports collection makefile for:   pear-DB_DataObject
# Date created:        23 August 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	DB_DataObject
PORTVERSION=	1.8.11
CATEGORIES=	databases pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An SQL Builder, Object Interface to Database Tables

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	DB
FILES=		DataObject.php DataObject/Cast.php DataObject/Generator.php \
		DataObject/createTables.php DataObject/Error.php
EXAMPLES=	example.ini
_EXAMPLESDIR=	docs

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_MDB2 "PEAR::MDB2 support" off \
		PEAR_VALIDATE "PEAR::Validate support" off

post-patch:
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/DataObject.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_MDB2)
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if defined(WITH_PEAR_VALIDATE)
RUN_DEPENDS+=	${PEARDIR}/Validate.php:${PORTSDIR}/devel/pear-Validate
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
