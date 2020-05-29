# $FreeBSD$

PORTNAME=	her
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ORM that maps REST resources to Ruby objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=4.2.1:databases/rubygem-activemodel4 \
		rubygem-faraday0>=0.8<1.0:www/rubygem-faraday0 \
		rubygem-multi_json>=1.7<2:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
