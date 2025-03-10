PORTNAME=	sidekiq
PORTVERSION=	7.2.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	72

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/ \
		https://github.com/sidekiq/sidekiq

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-concurrent-ruby>=0<2:devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.3.0:net/rubygem-connection_pool \
		rubygem-rack>=2.2.4,3:www/rubygem-rack \
		rubygem-redis-client>=0.19.0:databases/rubygem-redis-client

USES=		cpe gem
CPE_VENDOR=	contribsys

NO_ARCH=	yes
PORTSCOUT=	limit:^7\.2\.

PLIST_FILES=	bin/sidekiq \
		bin/sidekiqmon


.include <bsd.port.mk>
