# $FreeBSD$

PORTNAME=	rrd-ffi
PORTVERSION=	0.2.14
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Ruby bindings for RRD functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rrdtool:databases/rrdtool \
		rubygem-activesupport>=0:devel/rubygem-activesupport \
		rubygem-ffi>=0:devel/rubygem-ffi

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
