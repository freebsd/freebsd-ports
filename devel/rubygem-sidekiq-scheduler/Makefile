# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sidekiq-scheduler
PORTVERSION=	2.1.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight job scheduler extension for Sidekiq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis>=3:databases/rubygem-redis \
		rubygem-rufus-scheduler>=3.2:devel/rubygem-rufus-scheduler \
		rubygem-sidekiq>=3:devel/rubygem-sidekiq \
		rubygem-tilt>=1.4.0:devel/rubygem-tilt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
