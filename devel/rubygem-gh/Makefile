# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gh
PORTVERSION=	0.15.1
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Multi-layer client for the GitHub API v3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.4.0<3:www/rubygem-addressable \
		rubygem-faraday>=0.8<1:www/rubygem-faraday \
		rubygem-multi_json>=1.0<2:devel/rubygem-multi_json \
		rubygem-net-http-persistent2>=2.9<3:www/rubygem-net-http-persistent2 \
		rubygem-net-http-pipeline>=0:www/rubygem-net-http-pipeline

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/lib/gh.rb.orig ${WRKSRC}/gh.gemspec.orig

.include <bsd.port.mk>
