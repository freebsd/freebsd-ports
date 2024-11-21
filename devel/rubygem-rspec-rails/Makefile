PORTNAME=	rspec-rails
PORTVERSION=	7.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing framework for Rails
WWW=		https://rspec.info/ \
		https://github.com/rspec/rspec-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-actionpack70>=7.0:www/rubygem-actionpack70 \
		rubygem-activesupport70>=7.0:devel/rubygem-activesupport70 \
		rubygem-railties70>=7.0:www/rubygem-railties70 \
		rubygem-rspec-core>=3.13<4:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=3.13<4:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=3.13<4:devel/rubygem-rspec-mocks \
		rubygem-rspec-support>=3.13<4:devel/rubygem-rspec-support

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
