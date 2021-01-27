# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azure-storage-common
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Storage Common Client Library for Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-faraday>=1.0<2:www/rubygem-faraday \
		rubygem-faraday_middleware>=1.0.0<1.1:www/rubygem-faraday_middleware \
		rubygem-net-http-persistent>=4.0<5:www/rubygem-net-http-persistent \
		rubygem-nokogiri>=1.11.0.rc2<1.12:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
