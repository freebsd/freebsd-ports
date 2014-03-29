# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	grape-swagger
PORTVERSION=	0.7.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Documentation tool for grape APIs

LICENSE=	MIT

RUN_DEPENDS=	rubygem-grape>=0.2.0:${PORTSDIR}/devel/rubygem-grape \
		rubygem-grape-entity>=0.3.0:${PORTSDIR}/devel/rubygem-grape-entity \
		rubygem-kramdown>=1.3.1:${PORTSDIR}/textproc/rubygem-kramdown

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
