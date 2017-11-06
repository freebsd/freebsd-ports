# $FreeBSD$

PORTNAME=	peek-redis
PORTVERSION=	1.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Provide a peek into the Redis calls made

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-atomic>=1.0.0:devel/rubygem-atomic \
		rubygem-peek>=0:devel/rubygem-peek \
		rubygem-redis>=0:databases/rubygem-redis

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
