# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	rspec-rails
PORTVERSION=	5.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing framework for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-actionpack52>=5.2:www/rubygem-actionpack52 \
		rubygem-activesupport52>=5.2:devel/rubygem-activesupport52 \
		rubygem-railties52>=5.2:www/rubygem-railties52 \
		rubygem-rspec-core>=3.10<4:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=3.10<4:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=3.10<4:devel/rubygem-rspec-mocks \
		rubygem-rspec-support>=3.10<4:devel/rubygem-rspec-support

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
