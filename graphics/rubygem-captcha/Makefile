# Ports collection makefile for:	rubygem-captcha
# Date created:				13 March 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	captcha
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A simple CAPTCHA written in Ruby

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/GD.so:${PORTSDIR}/graphics/ruby-gd
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
