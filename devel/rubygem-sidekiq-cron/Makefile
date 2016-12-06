# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq-cron
PORTVERSION=	0.4.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enables to set jobs to be run in specified time (using CRON notation)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-redis-namespace>=1.5.2:databases/rubygem-redis-namespace \
		rubygem-rufus-scheduler>=2.0.24:devel/rubygem-rufus-scheduler \
		rubygem-sidekiq>=4.2.1:devel/rubygem-sidekiq

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
