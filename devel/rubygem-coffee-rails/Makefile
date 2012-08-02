# New ports collection makefile for:	rubygem-coffee-rails
# Date created:		2011-09-12
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coffee-rails
PORTVERSION=	3.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Coffee Script adapter for the Rails asset pipeline

RUN_DEPENDS=	rubygem-coffee-script>=2.2.0:${PORTSDIR}/devel/rubygem-coffee-script \
		rubygem-railties>=3.2.0:${PORTSDIR}/www/rubygem-railties

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
