PORTNAME=	apipie-bindings
PORTVERSION=	0.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for API calls that are documented with Apipie
WWW=		https://github.com/Apipie/apipie-bindings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gssapi>=1.3<2:security/rubygem-gssapi \
		rubygem-oauth>=1.1<2:net/rubygem-oauth \
		rubygem-rest-client>=2.0<3:www/rubygem-rest-client

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
