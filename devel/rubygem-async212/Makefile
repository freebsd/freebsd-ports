PORTNAME=	async
PORTVERSION=	2.12.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	212

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Modern asynchronous I/O framework for Ruby
WWW=		https://socketry.github.io/async/ \
		https://github.com/socketry/async

LICENSE=	MIT

RUN_DEPENDS=	rubygem-console>=1.25.2<2:devel/rubygem-console \
		rubygem-fiber-annotation>=0:devel/rubygem-fiber-annotation \
		rubygem-io-event>=1.6.5<2:devel/rubygem-io-event

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.12\.

.include <bsd.port.mk>
