# $FreeBSD$

PORTNAME=	cf-uaa-lib
PORTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client library for CloudFoundry UAA

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	rubygem-httpclient>=2.8.2.4:www/rubygem-httpclient \
		rubygem-multi_json>=0:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
