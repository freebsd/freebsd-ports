# $FreeBSD$

PORTNAME=	peek-redis
PORTVERSION=	1.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Provide a peek into the Redis calls made

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-atomic>=1.0.0:devel/rubygem-atomic \
		rubygem-peek-rails5>=0:devel/rubygem-peek-rails5 \
		rubygem-redis>=0:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
