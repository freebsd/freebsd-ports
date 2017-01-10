# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq
PORTVERSION=	4.2.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.0:devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.2:net/rubygem-connection_pool \
		rubygem-rack-protection>=1.5.0:www/rubygem-rack-protection \
		rubygem-redis>=3.2.1:databases/rubygem-redis

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/sidekiq bin/sidekiqctl

.include <bsd.port.mk>
