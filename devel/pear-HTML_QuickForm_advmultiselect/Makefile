# Ports collection makefile for:	pear-HTML_QuickForm_advmultiselect
# Date created:				11 November 2005
# Whom:					Chris St Denis <chris@ctgameinfo.com>
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm_advmultiselect
PORTVERSION=	1.0.0
CATEGORIES=	devel www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	chris@ctgameinfo.com
COMMENT=	Element for PEAR::HTML_QuickForm that defines a 2 box multi-select

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML/QuickForm
FILES=		advmultiselect.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
