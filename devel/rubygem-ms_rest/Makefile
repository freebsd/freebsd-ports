# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ms_rest
PORTVERSION=	0.7.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Azure Client Library for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-faraday>=0.9<1:www/rubygem-faraday \
		rubygem-timeliness>=0.3.10<1:devel/rubygem-timeliness

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
