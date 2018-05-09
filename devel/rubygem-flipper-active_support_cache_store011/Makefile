# $FreeBSD$

PORTNAME=	flipper-active_support_cache_store
PORTVERSION=	0.11.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	011

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActiveSupport::Cache store adapter for Flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=3.2:devel/rubygem-activesupport4 \
		rubygem-flipper011>=${PORTVERSION}:devel/rubygem-flipper011

PORTSCOUT=	limit:^0\.11\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
