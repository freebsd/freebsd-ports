# $FreeBSD$

PORTNAME=	Date_Holidays_USA
PORTVERSION=	0.1.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Driver based class to calculate holidays in the USA

BUILD_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays/Driver/USA.php
TESTS=		Date_Holidays_Driver_USA_TestSuite.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
