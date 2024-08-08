PORTNAME=	azure-storage-common
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Storage Common Client Library for Ruby
WWW=		https://github.com/Azure/azure-storage-ruby/tree/master/common \
		https://github.com/Azure/azure-storage-ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-faraday1>=1.0<2:www/rubygem-faraday1 \
		rubygem-faraday_middleware>=1.0.0<2:www/rubygem-faraday_middleware \
		rubygem-net-http-persistent>=4.0<5:www/rubygem-net-http-persistent \
		rubygem-nokogiri>=1.10.8<2:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
