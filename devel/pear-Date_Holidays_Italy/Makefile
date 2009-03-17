# New ports collection makefile for:	pear-Date_Holidays_Italy
# Date created:		2009-03-16
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Date_Holidays_Italy
PORTVERSION=	0.1.1
CATEGORIES=	devel www pear

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Driver based class to calculate holidays in Italy

BUILD_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays/Driver/Italy.php
TESTS=		Date_Holidays_Driver_Italy_TestSuite.php

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
