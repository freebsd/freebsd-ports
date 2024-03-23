PORTNAME=	async
PORTVERSION=	2.9.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern asynchronous I/O framework for Ruby
WWW=		https://github.com/socketry/async

LICENSE=	MIT

BROKEN_RUBY30=	yes

RUN_DEPENDS=	rubygem-console>=1.10<2:devel/rubygem-console \
		rubygem-fiber-annotation>=0:devel/rubygem-fiber-annotation \
		rubygem-io-event>=1.5.1<2:devel/rubygem-io-event \
		rubygem-timers>=4.1<5:devel/rubygem-timers

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
