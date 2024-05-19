PORTNAME=	sidekiq
PORTVERSION=	7.2.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/ \
		https://github.com/sidekiq/sidekiq

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-concurrent-ruby>=0<2:devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.3.0:net/rubygem-connection_pool \
		rubygem-rack>=2.2.4,3:www/rubygem-rack \
		rubygem-redis-client>=0.19.0:databases/rubygem-redis-client

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/sidekiq \
		bin/sidekiqmon

CPE_VENDOR=	contribsys

.include <bsd.port.mk>
