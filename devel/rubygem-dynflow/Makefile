PORTNAME=	dynflow
PORTVERSION=	1.8.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby workflow/orchestration engine
WWW=		https://dynflow.github.io/ \
		https://github.com/Dynflow/dynflow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-algebrick>=0.7.0<0.8:devel/rubygem-algebrick \
		rubygem-apipie-params>=0:devel/rubygem-apipie-params \
		rubygem-concurrent-ruby11>=1.1.3<1.2:devel/rubygem-concurrent-ruby11 \
		rubygem-concurrent-ruby-edge06>=0.6.0<0.7:devel/rubygem-concurrent-ruby-edge06 \
		rubygem-msgpack>=1.3.3<2:devel/rubygem-msgpack \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-sequel>=4.0.0:devel/rubygem-sequel

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
