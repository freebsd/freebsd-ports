PORTNAME=	errand
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby bindings for RRD
WWW=		https://rubygems.org/gems/errand

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	rrdtool:databases/rrdtool \
		rubygem-rrd-ffi>=0.2.13:devel/rubygem-rrd-ffi

NO_ARCH=	yes
USES=		gem

.include <bsd.port.mk>
