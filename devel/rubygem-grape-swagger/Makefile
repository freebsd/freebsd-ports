# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	grape-swagger
PORTVERSION=	0.20.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Documentation tool for grape APIs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-awesome_print>=0:devel/rubygem-awesome_print \
		rubygem-grape>=0:devel/rubygem-grape \
		rubygem-grape-entity>=0:devel/rubygem-grape-entity

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
