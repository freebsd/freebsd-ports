PORTNAME=	faraday_middleware-aws-sigv4
PORTVERSION=	1.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faraday middleware for AWS Signature Version 4
WWW=		https://github.com/winebarrel/faraday_middleware-aws-sigv4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sigv4>=1.0<2:devel/rubygem-aws-sigv4 \
		rubygem-faraday>=2.0<3:www/rubygem-faraday

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
