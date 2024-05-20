PORTNAME=	sidekiq
PORTVERSION=	7.1.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/ \
		https://github.com/sidekiq/sidekiq

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-concurrent-ruby>=0<2:devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.3.0:net/rubygem-connection_pool \
		rubygem-rack>=2.2.4,3:www/rubygem-rack \
		rubygem-redis-client>=0.14.0:databases/rubygem-redis-client

USES=		cpe gem
CPE_VENDOR=	contribsys

NO_ARCH=	yes
PORTSCOUT=	limit:^7\.1\.

PLIST_FILES=	bin/sidekiq \
		bin/sidekiqmon


.include <bsd.port.mk>
