PORTNAME=	validate_url
PORTVERSION=	1.0.13
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Validating urls in Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-activemodel61>=3.0:databases/rubygem-activemodel61 \
		rubygem-public_suffix>=0:dns/rubygem-public_suffix

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
