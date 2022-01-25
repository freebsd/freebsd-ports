PORTNAME=	redis-activesupport
PORTVERSION=	5.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Redis store for ActiveSupport::Cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-activesupport4>=3<8:devel/rubygem-activesupport4 \
		rubygem-redis-store>=1.3<2:devel/rubygem-redis-store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
