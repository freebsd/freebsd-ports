PORTNAME=	sidekiq
PORTVERSION=	7.3.9
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/ \
		https://github.com/sidekiq/sidekiq

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-connection_pool>=2.3.0:net/rubygem-connection_pool \
		rubygem-logger-gitlab>=0:devel/rubygem-logger-gitlab \
		rubygem-rack>=2.2.4,3:www/rubygem-rack \
		rubygem-redis-client>=0.22.2:databases/rubygem-redis-client

USES=		cpe gem
CPE_VENDOR=	contribsys

NO_ARCH=	yes
PORTSCOUT=	limit:^7\.3\.

PLIST_FILES=	bin/sidekiq \
		bin/sidekiqmon


.include <bsd.port.mk>
