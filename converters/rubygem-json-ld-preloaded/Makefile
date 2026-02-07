PORTNAME=	json-ld-preloaded
PORTVERSION=	3.3.2
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON-LD with preloaded contexts
WWW=		https://github.com/ruby-rdf/json-ld-preloaded

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-json-ld>=3.3<4:converters/rubygem-json-ld \
		rubygem-rdf>=3.3<4:www/rubygem-rdf

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
