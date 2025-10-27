PORTNAME=	libdatadog
PORTVERSION=	22.0.1.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rust-based utility library for Datadog ddtrace gem
WWW=		https://github.com/DataDog/libdatadog/tree/main/ruby

LICENSE=	APACHE20

LIB_DEPENDS=	libdatadog_profiling_ffi.so:devel/libdatadog

USES=		gem

NO_ARCH=	yes

# Clean up bundled libraries
post-patch:
	@${RM} -r ${WRKSR}/vendor/

.include <bsd.port.mk>
