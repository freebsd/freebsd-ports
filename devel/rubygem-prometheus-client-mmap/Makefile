PORTNAME=	prometheus-client-mmap
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Suite of instrumentation metric primitives
WWW=		https://gitlab.com/gitlab-org/prometheus-client-mmap

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-rb_sys>=0.9.86<1:lang/rubygem-rb_sys

USES=		cargo gem gmake llvm:build

# Required to be able to build the rust library the gem uses
GEMFILES:=	${DISTNAME}.gem
DISTFILES+=	${DISTNAME}.gem
GEMS_SKIP_SUBDIR=	1
CARGO_VENDOR_DIR=	${WRKSRC}/ext/fast_mmaped_file_rs/cargo-crates
CARGO_CARGOTOML=	${WRKSRC}/ext/fast_mmaped_file_rs/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/ext/fast_mmaped_file_rs/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
GEM_ENV+=	MAKE=gmake

# update the crates file with: make cargo-crates > Makefile.crates

# The port installs files writeable
# Is reported upstream: https://gitlab.com/gitlab-org/ruby/gems/prometheus-client-mmap/-/issues/60
post-extract:
	${CHMOD} -R o-w ${WRKSRC}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
RUBYGEM_ARGS+=		--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
