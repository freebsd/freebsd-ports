# Ports collection makefile for:  pear-HTML_QuickForm_SelectFilter
# Date created:			  15 December 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm_SelectFilter
PORTVERSION=	1.0.0
CATEGORIES=	devel www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}RC1

MAINTAINER=	antonio@php.net
COMMENT=	Element for PEAR::HTML_QuickForm that defines dynamic filters

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/QuickForm
FILES=		SelectFilter.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
