# $FreeBSD$

PORTNAME=	Date_Holidays_Slovenia
PORTVERSION=	0.1.2
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Driver based class to calculate holidays in Slovenia

BUILD_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays/Driver/Slovenia.php
TESTS=		Date_Holidays_Driver_Slovenia_TestSuite.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
