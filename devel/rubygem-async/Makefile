PORTNAME=	async
PORTVERSION=	2.27.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern asynchronous I/O framework for Ruby
WWW=		https://socketry.github.io/async/ \
		https://github.com/socketry/async

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-console>=1.29<2:devel/rubygem-console \
		rubygem-fiber-annotation>=0:devel/rubygem-fiber-annotation \
		rubygem-io-event>=1.11<2:devel/rubygem-io-event \
		rubygem-metrics>=0.12<1:devel/rubygem-metrics \
		rubygem-traces>=0.15<1:devel/rubygem-traces

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
