PORTNAME=	resque
PORTVERSION=	2.2.1
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Redis-backed Ruby library for queuing jobs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	rubygem-mono_logger>=1.0:devel/rubygem-mono_logger \
		rubygem-multi_json>=1.0:devel/rubygem-multi_json \
		rubygem-redis-namespace>1.6:databases/rubygem-redis-namespace \
		rubygem-sinatra>0.9.3:www/rubygem-sinatra \
		rubygem-vegas>=0.1.2:www/rubygem-vegas

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes:2.3+

.include <bsd.port.mk>
