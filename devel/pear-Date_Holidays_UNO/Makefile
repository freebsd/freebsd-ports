# $FreeBSD$

PORTNAME=	Date_Holidays_UNO
PORTVERSION=	0.1.3
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Driver based class to calculate holidays in the UNO

BUILD_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays/Driver/UNO.php
TESTS=		Date_Holidays_Driver_UNO_TestSuite.php

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
