PORTNAME=	rspec
PORTVERSION=	3.13.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Behaviour Driven Development in Ruby
WWW=		https://rspec.info/ \
		https://github.com/rspec/rspec/tree/main/rspec \
		https://github.com/rspec/rspec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rspec-core>=${PORTVERSION:R}.0<3.14:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=${PORTVERSION:R}.0<3.14:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=${PORTVERSION:R}.0<3.14:devel/rubygem-rspec-mocks

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
