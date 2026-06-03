PORTNAME=	rubocop-performance
PORTVERSION=	1.26.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of RuboCop cops to check for performance optimizations
WWW=		https://docs.rubocop.org/rubocop-performance/ \
		https://github.com/rubocop/rubocop-performance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-lint_roller>=1.1<2:devel/rubygem-lint_roller \
		rubygem-rubocop>=1.75.0<2.0:devel/rubygem-rubocop \
		rubygem-rubocop-ast>=1.47.1:devel/rubygem-rubocop-ast

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
