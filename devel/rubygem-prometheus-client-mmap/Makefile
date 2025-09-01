PORTNAME=	prometheus-client-mmap
PORTVERSION=	1.2.10
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Suite of instrumentation metric primitives
WWW=		https://gitlab.com/gitlab-org/prometheus-client-mmap

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-logger-gitlab>=0:devel/rubygem-logger-gitlab \
		rubygem-rb_sys>=0.9.109<0.10:lang/rubygem-rb_sys

USES=		cargo gem gmake llvm:build

# Required to be able to build the rust library the gem uses
GEMFILES:=	${DISTNAME}.gem
DISTFILES+=	${DISTNAME}.gem
GEMS_SKIP_SUBDIR=	1
CARGO_VENDOR_DIR=	${WRKSRC}/ext/fast_mmaped_file_rs/cargo-crates
CARGO_CARGOTOML=	${WRKSRC}/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
GEM_ENV+=	MAKE=gmake

# update the crates file with: make cargo-crates > Makefile.crates

# The port installs files writeable
# Is reported upstream: https://gitlab.com/gitlab-org/ruby/gems/prometheus-client-mmap/-/issues/60
post-extract:
	${CHMOD} -R o-w ${WRKSRC}

# The project has a Cargo.lock which is a symlink to main folder, cleanup this symlink
post-stage:
	${RM} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext/fast_mmaped_file_rs/Cargo.lock
	${FIND} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ext -type d -empty -delete 2> /dev/null || ${TRUE}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
RUBYGEM_ARGS+=		--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
