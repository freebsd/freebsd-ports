# $FreeBSD$

PORTNAME=	json-ld
DISTVERSION=	2.1.7
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	JSON-LD reader/writer for Ruby

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	rubygem-multi_json>=1.12:devel/rubygem-multi_json \
		rubygem-rdf>=2.2.8:www/rubygem-rdf

USES=		gem
USE_RUBY=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/jsonld

.include <bsd.port.mk>
