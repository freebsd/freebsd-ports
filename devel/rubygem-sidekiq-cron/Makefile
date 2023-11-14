PORTNAME=	sidekiq-cron
PORTVERSION=	1.11.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enables to set jobs to be run in specified time (using CRON notation)
WWW=		https://github.com/sidekiq-cron/sidekiq-cron

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fugit>=1.8<2:devel/rubygem-fugit \
		rubygem-globalid-rails61>=1.0.1:databases/rubygem-globalid-rails61 \
		rubygem-sidekiq>=6:devel/rubygem-sidekiq

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
