# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq
PORTVERSION=	3.2.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby

RUN_DEPENDS=	rubygem-celluloid>=0.15.2:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-connection_pool>=2.0.0:${PORTSDIR}/net/rubygem-connection_pool \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json \
		rubygem-redis>=3.0.4:${PORTSDIR}/databases/rubygem-redis \
		rubygem-redis-namespace>=1.3.1:${PORTSDIR}/databases/rubygem-redis-namespace

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sidekiqctl bin/sidekiq

.include <bsd.port.mk>
