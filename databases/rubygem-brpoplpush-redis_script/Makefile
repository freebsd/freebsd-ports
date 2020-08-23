# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brpoplpush-redis_script
PORTVERSION=	0.1.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bring your own LUA scripts into redis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.5<2:devel/rubygem-concurrent-ruby \
		rubygem-redis>=1.0<5.0:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

#NO_ARCH=	yes

.include <bsd.port.mk>
