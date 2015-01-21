# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gh
PORTVERSION=	0.13.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multi-layer client for the github api v3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUB_DEPENDS=	rubygem-addressable>=0:${PORTSDIR}/www/rubygem-addressable \
		rubygem-backports>=0:${PORTSDIR}/devel/rubygem-backports \
		rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-net-http-persistent>=2.7:${PORTSDIR}/www/rubygem-net-http-persistent \
		rubygem-net-http-pipeline>=0:${PORTSDIR}/www/rubygem-net-http-pipeline

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
