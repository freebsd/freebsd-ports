PORTNAME=	concurrent-ruby-edge
PORTVERSION=	0.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	06

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bleeding edge features for concurrent-ruby
WWW=		https://github.com/ruby-concurrency/concurrent-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-concurrent-ruby11>=1.1.6<1.2:devel/rubygem-concurrent-ruby11

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.6\.

.include <bsd.port.mk>
