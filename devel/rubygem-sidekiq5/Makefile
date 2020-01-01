# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq
PORTVERSION=	5.2.7
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-connection_pool>=2.2.2<3:net/rubygem-connection_pool \
		rubygem-rack>=1.5.0,3:www/rubygem-rack \
		rubygem-rack-protection>=1.5.0:www/rubygem-rack-protection \
		rubygem-redis>=3.3.5<5:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/sidekiq5 bin/sidekiqctl5

PORTSCOUT=	limit:^5\.

post-patch:
	@${MV} ${WRKSRC}/bin/sidekiq ${WRKSRC}/bin/sidekiq5
	@${MV} ${WRKSRC}/bin/sidekiqctl ${WRKSRC}/bin/sidekiqctl5

.include <bsd.port.mk>
