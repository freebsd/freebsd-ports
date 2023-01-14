PORTNAME=	json-ld
PORTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON-LD reader/writer for Ruby
WWW=		https://github.com/ruby-rdf/json-ld

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-json-canonicalization>=0.3<1:devel/rubygem-json-canonicalization \
		rubygem-htmlentities>=4.3<5:textproc/rubygem-htmlentities \
		rubygem-link_header>=0.0.8<1:www/rubygem-link_header \
		rubygem-multi_json>=1.15<2:devel/rubygem-multi_json \
		rubygem-rack22>=2.2,3<3,3:www/rubygem-rack22 \
		rubygem-rdf>=3.2.9<4:www/rubygem-rdf

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/jsonld

.include <bsd.port.mk>
