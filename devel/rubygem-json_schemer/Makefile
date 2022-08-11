PORTNAME=	json_schemer
PORTVERSION=	0.2.20
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby JSON schema validator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ecma-re-validator>=0.3<1:devel/rubygem-ecma-re-validator \
		rubygem-hana>=1.3<2:devel/rubygem-hana \
		rubygem-regexp_parser>=2.0<3:textproc/rubygem-regexp_parser \
		rubygem-uri_template>=0.7<1:net/rubygem-uri_template

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
