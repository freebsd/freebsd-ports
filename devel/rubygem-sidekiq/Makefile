# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq
PORTVERSION=	3.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-celluloid>=0.16.0:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-connection_pool>=2.1.1:${PORTSDIR}/net/rubygem-connection_pool \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json \
		rubygem-redis>=3.0.6:${PORTSDIR}/databases/rubygem-redis \
		rubygem-redis-namespace>=1.3.1:${PORTSDIR}/databases/rubygem-redis-namespace

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sidekiq bin/sidekiqctl

.include <bsd.port.mk>
