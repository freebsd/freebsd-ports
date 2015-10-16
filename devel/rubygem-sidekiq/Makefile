# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq
PORTVERSION=	3.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-celluloid>=0.17.2:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-connection_pool>=2.2:${PORTSDIR}/net/rubygem-connection_pool \
		rubygem-json>=1:${PORTSDIR}/devel/rubygem-json \
		rubygem-redis>=3.2.1:${PORTSDIR}/databases/rubygem-redis \
		rubygem-redis-namespace>=1.5.2:${PORTSDIR}/databases/rubygem-redis-namespace

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sidekiq bin/sidekiqctl

.include <bsd.port.mk>
