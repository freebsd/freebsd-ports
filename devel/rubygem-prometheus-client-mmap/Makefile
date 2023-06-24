PORTNAME=	prometheus-client-mmap
DISTVERSION=	0.25.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Suite of instrumentation metric primitives
WWW=		https://gitlab.com/gitlab-org/prometheus-client-mmap

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-rb_sys>=0.9<1:lang/rubygem-rb_sys

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
