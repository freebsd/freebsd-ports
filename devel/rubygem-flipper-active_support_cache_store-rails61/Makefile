PORTNAME=	flipper-active_support_cache_store
PORTVERSION=	0.25.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ActiveSupport::Cache store adapter for Flipper
WWW=		https://github.com/jnunemaker/flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport61>=5.0<7:devel/rubygem-activesupport61 \
		rubygem-flipper>=${PORTVERSION}<0.26:devel/rubygem-flipper

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
