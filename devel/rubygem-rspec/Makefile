# Created by: Roman Shterenzon <romanbsd@yahoo.com>
# $FreeBSD$

PORTNAME=	rspec
PORTVERSION=	3.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Behaviour Driven Development in Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rspec-core>=${PORTVERSION:R}:${PORTSDIR}/devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=${PORTVERSION:R}:${PORTSDIR}/devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=${PORTVERSION:R}:${PORTSDIR}/devel/rubygem-rspec-mocks

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
