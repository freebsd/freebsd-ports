PORTNAME=	sidekiq-scheduler
PORTVERSION=	5.0.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight job scheduler extension for Sidekiq
WWW=		https://sidekiq-scheduler.github.io/sidekiq-scheduler/ \
		https://github.com/sidekiq-scheduler/sidekiq-scheduler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rufus-scheduler>=3.2<4:devel/rubygem-rufus-scheduler \
		rubygem-sidekiq>=6<8:devel/rubygem-sidekiq \
		rubygem-tilt>=1.4.0<3:devel/rubygem-tilt

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
