# Ports collection makefile for:  pear-HTML_Select
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Select_Common
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Some small PEAR classes to handle common <select> lists

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common	\
		${PEARDIR}/I18N/Common.php:${PORTSDIR}/devel/pear-I18N
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML

FILES=		Select/Common/Country.php Select/Common/FRDepartements.php \
		Select/Common/UKCounty.php Select/Common/USState.php
EXAMPLES=	Country.php FRDepartements.php UKCounty.php USState.php
_EXAMPLESDIR=	Select/Common/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
