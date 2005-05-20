# Ports collection makefile for:  pear-HTML_CSS
# Date created:			  16 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_CSS
PORTVERSION=	0.2.0
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class for generating CSS declarations

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		CSS.php
EXAMPLES=	CSS_InHeader.php CSS_Inline.php CSS_Stylesheet.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
