# $FreeBSD$

PORTNAME=	faraday_middleware-multi_json
PORTVERSION=	0.0.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Faraday response parser using MultiJson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday_middleware>0:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-multi_json>0:${PORTSDIR}/devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
