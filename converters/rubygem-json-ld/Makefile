# $FreeBSD$

PORTNAME=	json-ld
PORTVERSION=	3.1.2
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON-LD reader/writer for Ruby

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-json-canonicalization>=0.2<1:devel/rubygem-json-canonicalization \
		rubygem-htmlentities>=4.3<5:textproc/rubygem-htmlentities \
		rubygem-link_header>=0.0.8<1:www/rubygem-link_header \
		rubygem-multi_json>=1.14<2:devel/rubygem-multi_json \
		rubygem-rack>=2.0,3<3,3:www/rubygem-rack \
		rubygem-rdf>=3.1<4:www/rubygem-rdf

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/jsonld

.include <bsd.port.mk>
