# $FreeBSD$

PORTNAME=	dynflow
PORTVERSION=	0.8.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	Ruby workflow/orchestration engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-algebrick>=0.7.0:${PORTSDIR}/devel/rubygem-algebrick \
		rubygem-apipie-params>=0:${PORTSDIR}/devel/rubygem-apipie-params \
		rubygem-concurrent-ruby>=1.0.0:${PORTSDIR}/devel/rubygem-concurrent-ruby \
		rubygem-concurrent-ruby-edge>=0.2.0:${PORTSDIR}/devel/rubygem-concurrent-ruby-edge \
		rubygem-multi_json>=0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-sequel>=0:${PORTSDIR}/devel/rubygem-sequel

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
