PORTNAME=	faraday-excon
PORTVERSION=	2.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faraday adapter for Excon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-excon>=0.27.4:devel/rubygem-excon \
		rubygem-faraday>=2.0<3:www/rubygem-faraday

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
