# $FreeBSD$

PORTNAME=	dynflow
PORTVERSION=	1.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby workflow/orchestration engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-algebrick>=0.7.0<0.8:devel/rubygem-algebrick \
		rubygem-apipie-params>=0:devel/rubygem-apipie-params \
		rubygem-concurrent-ruby>=1.1.3<1.2:devel/rubygem-concurrent-ruby \
		rubygem-concurrent-ruby-edge>=0.4.1<1:devel/rubygem-concurrent-ruby-edge \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-sequel>=4.0.0:devel/rubygem-sequel

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
