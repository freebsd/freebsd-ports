PORTNAME=	rubocop-capybara
PORTVERSION=	2.22.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Code style checking for Capybara test files
WWW=		https://docs.rubocop.org/rubocop-capybara/ \
		https://github.com/rubocop/rubocop-capybara

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-lint_roller>=1.1<2:devel/rubygem-lint_roller \
		rubygem-rubocop>=1.72.1<2:devel/rubygem-rubocop

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
