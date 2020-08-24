# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis-namespace
PORTVERSION=	1.7.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	17

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client class for Redis with namespace support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-redis>=3.0.4:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.7\.

.include <bsd.port.mk>
