PORTNAME=	sidekiq-unique-jobs
PORTVERSION=	7.1.29
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ensure only a single copy of a job is in Redis
WWW=		https://github.com/mhenrixon/sidekiq-unique-jobs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-brpoplpush-redis_script>=0.1.1<2.0.0:databases/rubygem-brpoplpush-redis_script \
		rubygem-concurrent-ruby>=1.0.5<2:devel/rubygem-concurrent-ruby \
		rubygem-redis4>=0<5.0:databases/rubygem-redis4 \
		rubygem-sidekiq6>=5.0<7.0:devel/rubygem-sidekiq6 \
		rubygem-thor>=0.20<3.0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/uniquejobs

.include <bsd.port.mk>
