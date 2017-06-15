# Created by: Roman Shterenzon <romanbsd@yahoo.com>
# $FreeBSD$

PORTNAME=	rspec
PORTVERSION=	3.5.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Behaviour Driven Development in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rspec-core>=${PORTVERSION:R}:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=${PORTVERSION:R}:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=${PORTVERSION:R}:devel/rubygem-rspec-mocks

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
