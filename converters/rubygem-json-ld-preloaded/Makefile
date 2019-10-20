# $FreeBSD$

PORTNAME=	json-ld-preloaded
PORTVERSION=	3.0.6
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON-LD with preloaded contexts

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-json-ld>=3.0:converters/rubygem-json-ld \
		rubygem-multi_json>=1.12:devel/rubygem-multi_json \
		rubygem-rdf>=3.0:www/rubygem-rdf

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
