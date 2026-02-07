PORTNAME=	resque
PORTVERSION=	2.7.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Redis-backed Ruby library for queuing jobs
WWW=		https://resque.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	rubygem-mono_logger>=1.0:devel/rubygem-mono_logger \
		rubygem-multi_json>=1.0:devel/rubygem-multi_json \
		rubygem-redis-namespace>1.6:databases/rubygem-redis-namespace \
		rubygem-sinatra>0.9.3:www/rubygem-sinatra

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
