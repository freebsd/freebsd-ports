PORTNAME=	rubocop-rspec
PORTVERSION=	3.8.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RuboCop plugin of code style checking for RSpec files
WWW=		https://docs.rubocop.org/rubocop-rspec/ \
		https://github.com/rubocop/rubocop-rspec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-lint_roller>=1.1<2:devel/rubygem-lint_roller \
		rubygem-rubocop>=1.81<2:devel/rubygem-rubocop

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
