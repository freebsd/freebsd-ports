# $FreeBSD$

PORTNAME=	redis-namespace
PORTVERSION=	1.5.3
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	15

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client class for Redis with namespace support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-redis3>=3.0.4:databases/rubygem-redis3

PORTSCOUT=	limit:^1\.5

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
