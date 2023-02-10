PORTNAME=	rspec
PORTVERSION=	3.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development in Ruby
WWW=		https://github.com/rspec/rspec-metagem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rspec-core>=${PORTVERSION:R}.0<3.13:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=${PORTVERSION:R}.0<3.13:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=${PORTVERSION:R}.0<3.13:devel/rubygem-rspec-mocks

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
