PORTNAME=	dry-types
PORTVERSION=	1.8.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Type system for Ruby supporting coercions, constraints and complex types
WWW=		https://github.com/dry-rb/dry-types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>=3.0<4:math/rubygem-bigdecimal \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-dry-core>=1.0<2:devel/rubygem-dry-core \
		rubygem-dry-inflector>=1.0<2:devel/rubygem-dry-inflector \
		rubygem-dry-logic>=1.4<2:devel/rubygem-dry-logic \
		rubygem-zeitwerk>=2.6<3:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
