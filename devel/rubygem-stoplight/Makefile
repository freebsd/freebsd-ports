PORTNAME=	stoplight
PORTVERSION=	5.8.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the circuit breaker pattern
WWW=		https://github.com/bolshakov/stoplight

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-concurrent-ruby>=0:devel/rubygem-concurrent-ruby \
		rubygem-zeitwerk>=0:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
