PORTNAME=	rbs_json_schema
PORTVERSION=	0.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate RBS type definitions from JSON schema

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport61>=5.0.0:devel/rubygem-activesupport61 \
		rubygem-rbs>=1.5.0:devel/rubygem-rbs

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rbs_json_schema

.include <bsd.port.mk>
