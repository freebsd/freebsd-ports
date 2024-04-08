PORTNAME=	rubocop-rspec
PORTVERSION=	2.29.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RuboCop plugin of code style checking for RSpec files
WWW=		https://github.com/rubocop/rubocop-rspec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-rubocop>=1.40<2:devel/rubygem-rubocop \
		rubygem-rubocop-capybara>=2.17<3:devel/rubygem-rubocop-capybara \
		rubygem-rubocop-factory_bot>=2.22<3:devel/rubygem-rubocop-factory_bot \
		rubygem-rubocop-rspec_rails>=2.28<3:devel/rubygem-rubocop-rspec_rails

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
