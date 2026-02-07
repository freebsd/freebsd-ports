PORTNAME=	json-ld
PORTVERSION=	3.3.2
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON-LD reader/writer for Ruby
WWW=		https://github.com/ruby-rdf/json-ld

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-json-canonicalization>=1.0<2:devel/rubygem-json-canonicalization \
		rubygem-htmlentities>=4.3<5:textproc/rubygem-htmlentities \
		rubygem-link_header>=0.0.8<1:www/rubygem-link_header \
		rubygem-multi_json>=1.15<2:devel/rubygem-multi_json \
		rubygem-rack>=2.2,3<4,3:www/rubygem-rack \
		rubygem-rdf>=3.3<4:www/rubygem-rdf \
		rubygem-rexml>=3.2<4:textproc/rubygem-rexml

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/jsonld

.include <bsd.port.mk>
