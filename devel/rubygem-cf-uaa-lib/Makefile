# $FreeBSD$

PORTNAME=	cf-uaa-lib
PORTVERSION=	3.13.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client library for CloudFoundry UAA

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-httpclient>=2.8.2.4<3:www/rubygem-httpclient \
		rubygem-multi_json>=1.12.1<2:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
