PORTNAME=	active_scaffold
PORTVERSION=	3.6.15
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Gem to handle all CRUD user interface needs
WWW=		https://github.com/activescaffold/active_scaffold

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-cow_proxy>=0.3<1:devel/rubygem-cow_proxy \
		rubygem-ice_nine>=0.11<1:devel/rubygem-ice_nine \
		rubygem-rails61>=4.2.0<6.2:www/rubygem-rails61 \
		rubygem-request_store>=1.3<2:devel/rubygem-request_store

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
