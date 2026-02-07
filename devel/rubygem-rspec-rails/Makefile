PORTNAME=	rspec-rails
PORTVERSION=	8.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing framework for Rails
WWW=		https://rspec.info/ \
		https://github.com/rspec/rspec-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-actionpack80>=7.2:www/rubygem-actionpack80 \
		rubygem-activesupport80>=7.2:devel/rubygem-activesupport80 \
		rubygem-railties80>=7.2:www/rubygem-railties80 \
		rubygem-rspec-core>=3.13<4:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=3.13<4:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=3.13<4:devel/rubygem-rspec-mocks \
		rubygem-rspec-support>=3.13<4:devel/rubygem-rspec-support

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
