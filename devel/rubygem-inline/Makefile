# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inline
PORTVERSION=	3.12.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	RubyInline-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Inline::C allows you to embed C/Ruby directly in ruby scripts

RUN_DEPENDS=	sow:${PORTSDIR}/devel/rubygem-hoe \
    		zentest:${PORTSDIR}/devel/rubygem-zentest

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
