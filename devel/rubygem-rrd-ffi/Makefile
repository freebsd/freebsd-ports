PORTNAME=	rrd-ffi
PORTVERSION=	0.2.14
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Ruby bindings for RRD functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rrdtool:databases/rrdtool \
		rubygem-activesupport4>=0:devel/rubygem-activesupport4 \
		rubygem-ffi>=0:devel/rubygem-ffi

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
