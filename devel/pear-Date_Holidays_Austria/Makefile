# New ports collection makefile for:	pear-Date_Holidays_Austria
# Date created:		2008-06-04
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Date_Holidays_Austria
PORTVERSION=	0.1.4
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Driver based class to calculate holidays in Austria

BUILD_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays/Driver/Austria.php
TESTS=		Date_Holidays_Driver_Austria_TestSuite.php

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
