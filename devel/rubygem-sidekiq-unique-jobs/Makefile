# $FreeBSD$

PORTNAME=	sidekiq-unique-jobs
PORTVERSION=	6.0.19
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ensure only a single copy of a job is in Redis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.5<2:devel/rubygem-concurrent-ruby \
		rubygem-sidekiq>=4.0<7.0:devel/rubygem-sidekiq \
		rubygem-thor>=0<1:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/uniquejobs

.include <bsd.port.mk>
