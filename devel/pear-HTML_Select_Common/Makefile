# Ports collection makefile for:  pear-HTML_Select
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Select_Common
PORTVERSION=	1.2.0
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Some small PEAR classes to handle common <select> lists

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common	\
		${PEARDIR}/I18N/Common.php:${PORTSDIR}/devel/pear-I18N
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		HTML/Select/Common/BRState.php \
		HTML/Select/Common/Country.php \
		HTML/Select/Common/FRDepartements.php \
		HTML/Select/Common/NOFylke.php \
		HTML/Select/Common/NOKommune.php \
		HTML/Select/Common/UKCounty.php \
		HTML/Select/Common/USState.php
EXAMPLES=	Country.php UKCounty.php USState.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
