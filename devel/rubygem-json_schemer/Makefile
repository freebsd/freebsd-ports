PORTNAME=	json_schemer
PORTVERSION=	2.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby JSON schema validator
WWW=		https://github.com/ruby-json-schema/json-schema

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-hana>=1.3<2:devel/rubygem-hana \
		rubygem-regexp_parser>=2.0<3:textproc/rubygem-regexp_parser \
		rubygem-simpleidn02>=0.2<1:dns/rubygem-simpleidn02

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/json_schemer

.include <bsd.port.mk>
