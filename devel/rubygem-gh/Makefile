PORTNAME=	gh
PORTVERSION=	0.18.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Multi-layer client for the GitHub API v3
WWW=		https://github.com/travis-ci/gh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=5.0<6:devel/rubygem-activesupport52 \
		rubygem-addressable>=2.4<3:www/rubygem-addressable \
		rubygem-faraday1>=1.0<2:www/rubygem-faraday1 \
		rubygem-faraday_middleware>=1.0<2:www/rubygem-faraday_middleware \
		rubygem-multi_json>=1.0<2:devel/rubygem-multi_json \
		rubygem-net-http-persistent2>=2.9<3:www/rubygem-net-http-persistent2 \
		rubygem-net-http-pipeline>=0:www/rubygem-net-http-pipeline

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
