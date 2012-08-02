# New ports collection makefile for:	rubygem-coffee-script
# Date created:		2011-09-11
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coffee-script
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby CoffeeScript is a bridge to the JS CoffeeScript compiler

RUN_DEPENDS=	rubygem-coffee-script-source>=0:${PORTSDIR}/devel/rubygem-coffee-script-source \
		rubygem-execjs>=0:${PORTSDIR}/devel/rubygem-execjs

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
