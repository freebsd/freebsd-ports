PORTNAME=	rubocop-performance
PORTVERSION=	1.18.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of RuboCop cops to check for performance optimizations
WWW=		https://github.com/rubocop/rubocop-performance

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rubocop>=1.7.0<2.0:devel/rubygem-rubocop \
		rubygem-rubocop-ast>=0.4.0:devel/rubygem-rubocop-ast

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
