# $FreeBSD$

PORTNAME=	rrd-ffi
PORTVERSION=	0.2.14
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Ruby bindings for RRD functions

LICENSE=	MIT

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool \
		rubygem-activesupport>=0:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-ffi>=0:${PORTSDIR}/devel/rubygem-ffi

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
