# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	sidekiq-scheduler
PORTVERSION=	4.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight job scheduler extension for Sidekiq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis>=4.2.0:databases/rubygem-redis \
		rubygem-rufus-scheduler>=3.2<4:devel/rubygem-rufus-scheduler \
		rubygem-sidekiq>=4:devel/rubygem-sidekiq \
		rubygem-tilt>=1.4.0:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
