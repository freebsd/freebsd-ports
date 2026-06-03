PORTNAME=	rubocop-factory_bot
PORTVERSION=	2.28.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Plugin for the RuboCop code style enforcing & linting tool
WWW=		https://docs.rubocop.org/rubocop-factory_bot/ \
		https://github.com/rubocop/rubocop-factory_bot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.md

RUN_DEPENDS=	rubygem-lint_roller>=1.1<2:devel/rubygem-lint_roller \
		rubygem-rubocop>=1.72.1<2:devel/rubygem-rubocop

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
