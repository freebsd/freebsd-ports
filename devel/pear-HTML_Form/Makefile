# Ports collection makefile for:  pear-HTML_Form
# Date created:			  27 October 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Form
PORTVERSION=	1.1.1
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Simple HTML form package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		HTML/Form.php
TESTS=		form.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
