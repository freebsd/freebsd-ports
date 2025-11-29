PORTNAME=	rubocop-rspec_rails
PORTVERSION=	2.32.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Code style checking for RSpec Rails files
WWW=		https://docs.rubocop.org/rubocop-rspec_rails/ \
		https://github.com/rubocop/rubocop-rspec_rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-lint_roller>=1.1<2:devel/rubygem-lint_roller \
		rubygem-rubocop>=1.72.1<2:devel/rubygem-rubocop \
		rubygem-rubocop-rspec>=3.5<4:devel/rubygem-rubocop-rspec

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
