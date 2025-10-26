PORTNAME=	sidekiq-cron
PORTVERSION=	1.12.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Enables to set jobs to be run in specified time (using CRON notation)
WWW=		https://github.com/sidekiq-cron/sidekiq-cron

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fugit-gitlab>=1.8<2:devel/rubygem-fugit-gitlab \
		rubygem-globalid-rails-gitlab>=1.0.1:databases/rubygem-globalid-rails-gitlab \
		rubygem-sidekiq-gitlab>=6:devel/rubygem-sidekiq-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
