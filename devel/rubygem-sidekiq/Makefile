# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq
PORTVERSION=	4.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.0:${PORTSDIR}/devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.2:${PORTSDIR}/net/rubygem-connection_pool \
		rubygem-json>=1:${PORTSDIR}/devel/rubygem-json \
		rubygem-redis>=3.2.1:${PORTSDIR}/databases/rubygem-redis

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sidekiq bin/sidekiqctl

.include <bsd.port.mk>
