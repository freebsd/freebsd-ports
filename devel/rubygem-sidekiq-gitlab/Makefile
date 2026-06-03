PORTNAME=	sidekiq
PORTVERSION=	7.3.9
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

PATCH_SITES=	https://gitlab.com/gitlab-org/gitlab/-/raw/18-7-stable-ee/vendor/gems/sidekiq/patches/
PATCHFILES+=	0001-Update-zrange-calls-to-be-Redis-6.0-compatible.patch:-p1 # 
#PATCHFILES+=	0002-Update-Sidekiq-gemspec-to-avoid-use-of-git.patch:-p1
PATCHFILES+=	0003-Add-support-for-configuring-Web-UI-asset-paths.patch:-p1 # https://github.com/sidekiq/sidekiq/pull/6865

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple, efficient background processing for Ruby
WWW=		https://sidekiq.org/ \
		https://github.com/sidekiq/sidekiq

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-connection_pool>=2.3.0:net/rubygem-connection_pool \
		rubygem-logger-gitlab>=0:devel/rubygem-logger-gitlab \
		rubygem-rack>=2.2.4,3:www/rubygem-rack \
		rubygem-redis-client>=0.22.2:databases/rubygem-redis-client

USES=		cpe gem
CPE_VENDOR=	contribsys

NO_ARCH=	yes
PORTSCOUT=	limit:^7\.3\.

PLIST_FILES=	bin/sidekiq \
		bin/sidekiqmon


.include <bsd.port.mk>
