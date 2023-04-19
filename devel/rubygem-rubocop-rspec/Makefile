PORTNAME=	rubocop-rspec
PORTVERSION=	2.20.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RuboCop plugin of code style checking for RSpec files
WWW=		https://github.com/rubocop/rubocop-rspec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-rubocop>=1.33<2:devel/rubygem-rubocop \
		rubygem-rubocop-capybara>=2.17<3:devel/rubygem-rubocop-capybara

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
