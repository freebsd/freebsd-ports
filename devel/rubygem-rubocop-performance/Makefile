PORTNAME=	rubocop-performance
PORTVERSION=	1.14.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of RuboCop cops to check for performance optimizations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rubocop>=1.7.0<2.0:devel/rubygem-rubocop \
		rubygem-rubocop-ast>=0.4.0:devel/rubygem-rubocop-ast

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
