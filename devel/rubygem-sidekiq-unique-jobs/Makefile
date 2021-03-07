# $FreeBSD$

PORTNAME=	sidekiq-unique-jobs
PORTVERSION=	7.0.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ensure only a single copy of a job is in Redis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-brpoplpush-redis_script>=0.0.0<2.0.0:databases/rubygem-brpoplpush-redis_script \
		rubygem-concurrent-ruby>=1.0.5<2:devel/rubygem-concurrent-ruby \
		rubygem-sidekiq>=5.0<7.0:devel/rubygem-sidekiq \
		rubygem-thor>=0.20<2.0:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/uniquejobs

.include <bsd.port.mk>
