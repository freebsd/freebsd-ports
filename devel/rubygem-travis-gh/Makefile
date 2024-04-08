PORTNAME=	travis-gh
PORTVERSION=	0.21.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multi-layer client for the GitHub API v3
WWW=		https://github.com/travis-ci/gh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=7.0.8<7.1:devel/rubygem-activesupport70 \
		rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-faraday>=2<3:www/rubygem-faraday \
		rubygem-faraday-retry>=0:www/rubygem-faraday-retry \
		rubygem-faraday-typhoeus>=0:www/rubygem-faraday-typhoeus \
		rubygem-multi_json>=1<2:devel/rubygem-multi_json \
		rubygem-net-http-persistent>=4<5:www/rubygem-net-http-persistent \
		rubygem-net-http-pipeline>=0:www/rubygem-net-http-pipeline

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
