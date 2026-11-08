PORTNAME=	sidekiq
PORTVERSION=	8.1.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/ \
		https://github.com/sidekiq/sidekiq

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-connection_pool>=3.0.0:net/rubygem-connection_pool \
		rubygem-json>=2.16.0:devel/rubygem-json \
		rubygem-logger>=1.7.0:devel/rubygem-logger \
		rubygem-rack>=3.2.0,3:www/rubygem-rack \
		rubygem-redis-client>=0.29.0:databases/rubygem-redis-client

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/kiq \
		bin/sidekiq \
		bin/sidekiqmon

CPE_VENDOR=	contribsys

.include <bsd.port.mk>
