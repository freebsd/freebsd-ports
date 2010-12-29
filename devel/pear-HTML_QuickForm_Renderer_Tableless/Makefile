# Ports collection makefile for:        HTML_QuickForm_Renderer_Tableless
# Date created:                         25 October 2010
# Whom:                                 Chris St Denis <chris@smartt.com>
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm_Renderer_Tableless
PORTVERSION=	0.6.1
CATEGORIES=	devel www pear

MAINTAINER=	chris@smartt.com
COMMENT=	Implementation of Tableless Renderer for HTML_QuickForm

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		HTML/QuickForm/Renderer/Tableless.php

_EXAMPLESDIR=	docs/examples
EXAMPLES=	contact.php

DATA=		stylesheet.css

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
