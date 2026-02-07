PORTNAME=	flipper-active_support_cache_store
PORTVERSION=	0.28.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ActiveSupport::Cache store adapter for Flipper
WWW=		https://github.com/jnunemaker/flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport-gitlab>=4.2<8:devel/rubygem-activesupport-gitlab \
		rubygem-flipper-gitlab>=${PORTVERSION}<0.29:devel/rubygem-flipper-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
