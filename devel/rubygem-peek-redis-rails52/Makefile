PORTNAME=	peek-redis
PORTVERSION=	1.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Provide a peek into the Redis calls made
WWW=		https://github.com/peek/peek-redis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-atomic>=1.0.0:devel/rubygem-atomic \
		rubygem-peek-rails52>=0:devel/rubygem-peek-rails52 \
		rubygem-redis>=0:databases/rubygem-redis

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
