PORTNAME=	prometheus-client-mmap
DISTVERSION=	0.28.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Suite of instrumentation metric primitives
WWW=		https://gitlab.com/gitlab-org/prometheus-client-mmap

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-rb_sys>=0.9<1:lang/rubygem-rb_sys

USES=		gem
# needs to be migrated to rust
#USES=		cargo gem
#GEMFILES=	${GEM_NAME}${EXTRACT_SUFX}
#CARGO_CARGOTOML=	${WRKSRC}/ext/fast_mmaped_file_rs/Cargo.toml
#CARGO_CARGOLOCK=	${WRKSRC}/ext/fast_mmaped_file_rs/Cargo.lock

# Generate with: make cargo-crates
# 85dd

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
