# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	familia
PORTVERSION=	0.7.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Organize and store ruby objects in Redis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-gibbler>=0.8.6:devel/rubygem-gibbler \
		rubygem-multi_json>=0.0.5:devel/rubygem-multi_json \
		rubygem-redis>=2.1.0:databases/rubygem-redis \
		rubygem-storable>=0.8.6:devel/rubygem-storable \
		rubygem-uri-redis>=0.4.2:net/rubygem-uri-redis

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
