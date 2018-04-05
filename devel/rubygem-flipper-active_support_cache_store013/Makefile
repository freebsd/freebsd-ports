# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flipper-active_support_cache_store
PORTVERSION=	0.13.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	013

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ActiveSupport::Cache store adapter for Flipper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=3.2:devel/rubygem-activesupport4 \
		rubygem-flipper013>=${PORTVERSION}:devel/rubygem-flipper013

PORTSCOUT=	limit:^0\.13\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
