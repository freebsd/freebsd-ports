# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	message_bus
PORTVERSION=	1.0.16
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Message bus for rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rack16>=1.1.3:www/rubygem-rack16 \
		rubygem-redis>=0:databases/rubygem-redis

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
