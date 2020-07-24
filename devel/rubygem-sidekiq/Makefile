# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq
PORTVERSION=	6.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-connection_pool>=2.2.2:net/rubygem-connection_pool \
		rubygem-rack>=2.0,3<3,3:www/rubygem-rack \
		rubygem-redis>=4.2.0:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/sidekiq bin/sidekiqmon

.include <bsd.port.mk>
