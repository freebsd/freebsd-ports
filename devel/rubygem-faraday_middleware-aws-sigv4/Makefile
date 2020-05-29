# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faraday_middleware-aws-sigv4
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faraday middleware for AWS Signature Version 4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sigv4>=1.0<2:devel/rubygem-aws-sigv4 \
		rubygem-faraday0>=0.15:www/rubygem-faraday0

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
