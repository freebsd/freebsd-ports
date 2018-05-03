# $FreeBSD$

PORTNAME=	her
PORTVERSION=	1.0.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ORM that maps REST resources to Ruby objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=4.2.1:databases/rubygem-activemodel4 \
		rubygem-faraday>=0.8:www/rubygem-faraday \
		rubygem-multi_json>=1.7:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
