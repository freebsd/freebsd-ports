# New ports collection makefile for:	pear-Date_Holidays_Denmark
# Date created:		2008-06-04
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Date_Holidays_Denmark
PORTVERSION=	0.1.3
CATEGORIES=	devel www pear

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Driver based class to calculate holidays in Denmark

BUILD_DEPENDS=	${PEARDIR}/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Date
FILES=		Holidays/Driver/Denmark.php

PLIST_SUB=      PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
