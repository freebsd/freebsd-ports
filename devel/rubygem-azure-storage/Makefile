# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	azure-storage
PORTVERSION=	0.15.0.preview
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Storage Client Library for Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-azure-core>=0.1<1:net/rubygem-azure-core \
		rubygem-faraday0>=0.9<1:www/rubygem-faraday0 \
		rubygem-faraday_middleware0>=0.10<1:www/rubygem-faraday_middleware0 \
		rubygem-nokogiri>=1.6.8<2:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
