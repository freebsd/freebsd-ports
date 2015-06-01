# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	message_bus
PORTVERSION=	1.0.12
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Message bus for rack

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rack15>=1.1.3:${PORTSDIR}/www/rubygem-rack15 \
		rubygem-redis>=0:${PORTSDIR}/databases/rubygem-redis

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
