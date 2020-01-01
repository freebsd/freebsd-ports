# Created by: Roman Shterenzon <romanbsd@yahoo.com>
# $FreeBSD$

PORTNAME=	rspec
PORTVERSION=	3.9.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rspec-core>=${PORTVERSION:R}.0<3.10:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=${PORTVERSION:R}.0<3.10:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=${PORTVERSION:R}.0<3.10:devel/rubygem-rspec-mocks

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
