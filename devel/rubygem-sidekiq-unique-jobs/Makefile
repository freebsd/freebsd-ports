# $FreeBSD$

PORTNAME=	sidekiq-unique-jobs
PORTVERSION=	5.0.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Ensure only a single copy of a job is in Redis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-sidekiq>=4.0:devel/rubygem-sidekiq \
		rubygem-thor>=0:devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/jobs

.include <bsd.port.mk>
