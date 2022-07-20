PORTNAME=	rspec-core
PORTVERSION=	3.11.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RSpec Core provides the structure for writing executable examples

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-rspec-support>=${PORTVERSION:R}.0<3.12:devel/rubygem-rspec-support

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rspec

.include <bsd.port.mk>
