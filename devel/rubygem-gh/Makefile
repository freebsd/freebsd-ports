# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gh
PORTVERSION=	0.18.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Multi-layer client for the GitHub API v3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=5.0<6:devel/rubygem-activesupport52 \
		rubygem-addressable>=2.4<3:www/rubygem-addressable \
		rubygem-faraday>=1.0<2:www/rubygem-faraday \
		rubygem-faraday_middleware>=1.0<2:www/rubygem-faraday_middleware \
		rubygem-multi_json>=1.0<2:devel/rubygem-multi_json \
		rubygem-net-http-persistent2>=2.9<3:www/rubygem-net-http-persistent2 \
		rubygem-net-http-pipeline>=0:www/rubygem-net-http-pipeline

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
