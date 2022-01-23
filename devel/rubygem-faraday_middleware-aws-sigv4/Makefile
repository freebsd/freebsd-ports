# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	faraday_middleware-aws-sigv4
PORTVERSION=	0.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faraday middleware for AWS Signature Version 4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sigv4>=1.0<2:devel/rubygem-aws-sigv4 \
		rubygem-faraday>=1.8<2:www/rubygem-faraday

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
