# Once the bootstraps are available on pkg.FreeBSD.org run sync.sh
# to upload them to ~/public_distfiles on freefall in preparation
# for the next lang/rust update.
PORTNAME=	rust
PORTVERSION=	1.89.0
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/
PKGNAMEPREFIX=	${FLAVOR:S/_/-/g}-
PKGNAMESUFFIX=	-bootstrap
DISTNAME=	${PORTNAME}c-${PORTVERSION}-src
DIST_SUBDIR=	rust

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Create bootstrap compilers for building lang/rust
WWW=		https://www.rust-lang.org/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	untested on other architectures

BUILD_DEPENDS=	${FLAVOR:S/_/-/g}-freebsd-sysroot>=a2021.09.14:devel/freebsd-sysroot@${FLAVOR} \
		cmake:devel/cmake-core \
		gmake:devel/gmake \
		rust>=${PORTVERSION}:lang/rust

FLAVORS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le riscv64
FLAVOR?=	${FLAVORS:[1]}

USES=		cpe ninja:build perl5 python:build tar:xz
CPE_VENDOR=	${PORTNAME}-lang
# for openssl-src crate
USE_PERL5=	build
PATCHDIR=	${.CURDIR}/../rust/files
# rustc stashes intermediary files in TMPDIR (default /tmp) which
# might cause issues for users that for some reason space limit
# their /tmp.  WRKDIR should have plenty of space.
# ?= to allow users to still overwrite it in make.conf.
TMPDIR?=	${WRKDIR}
# Resulting packages are not specific to amd64
NO_ARCH=	yes

_CARGO_VENDOR_DIR=			${WRKSRC}/vendor
_RUST_ARCH_amd64=			x86_64
_RUST_ARCH_i386=			i686
_RUST_ARCH_powerpc64=			powerpc64
_RUST_ARCH_riscv64=			riscv64gc
_RUST_HOST=				${_RUST_ARCH_${ARCH}:U${ARCH}}-unknown-${OPSYS:tl}
_RUST_TARGET=				${_RUST_ARCH_${FLAVOR}:U${FLAVOR}}-unknown-${OPSYS:tl}
_RUST_LLVM_TARGET=			${_RUST_LLVM_TARGET_${FLAVOR}}
_RUST_LLVM_TARGET_aarch64=		AArch64
_RUST_LLVM_TARGET_amd64=		X86
_RUST_LLVM_TARGET_armv7=		ARM
_RUST_LLVM_TARGET_i386=			X86
_RUST_LLVM_TARGET_powerpc64=		PowerPC
_RUST_LLVM_TARGET_powerpc64le=		PowerPC
_RUST_LLVM_TARGET_powerpc=		PowerPC
_RUST_LLVM_TARGET_riscv64=		RISCV

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=	is only for FreeBSD
.endif

.if exists(${PATCHDIR}/${FLAVOR:S/_/-/})
EXTRA_PATCHES+=	${PATCHDIR}/${FLAVOR:S/_/-/}
.endif

post-patch:
# Disable vendor checksums
	@${REINPLACE_CMD} 's,"files":{[^}]*},"files":{},' \
		${_CARGO_VENDOR_DIR}/*/.cargo-checksum.json

do-configure:
# Check that the running kernel has COMPAT_FREEBSD11 required by lang/rust post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh
	@${ECHO_CMD} '# https://github.com/rust-lang/rust/issues/135358 (bug #947897)' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'profile="dist"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} '[build]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'build-dir="${WRKDIR}/_build"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'vendor=true' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'extended=true' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'python="${PYTHON_CMD}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'docs=false' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'verbose=2' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cargo-native-static=true' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cargo="${LOCALBASE}/bin/cargo"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'rustc="${LOCALBASE}/bin/rustc"' >> ${WRKSRC}/config.toml
.if ${_RUST_HOST} != ${_RUST_TARGET}
	@${ECHO_CMD} 'host=["${_RUST_HOST}","${_RUST_TARGET}"]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'target=["${_RUST_TARGET}"]' >> ${WRKSRC}/config.toml
.endif
	@${ECHO_CMD} '[rust]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'channel="stable"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'default-linker="${CC}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'deny-warnings=false' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} '[llvm]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'download-ci-llvm=false' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'link-shared=false' >> ${WRKSRC}/config.toml
.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
	@${ECHO_CMD} 'ccache="${CCACHE_BIN}"' >> ${WRKSRC}/config.toml
.else
	@${ECHO_CMD} 'ccache=false' >> ${WRKSRC}/config.toml
.endif
# https://github.com/rust-lang/rust/pull/72696#issuecomment-641517185
	@${ECHO_CMD} 'ldflags="-lz"' >> ${WRKSRC}/config.toml
# we need to make sure to always build llvm with host arch support to get a
# host compiler that can build the host->target compiler
	@${ECHO_CMD} 'targets="${_RUST_LLVM_TARGET};${_RUST_LLVM_TARGET_${ARCH}}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} '[target.${_RUST_TARGET}]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cc="${LOCALBASE}/freebsd-sysroot/${FLAVOR:S/_/-/g}/bin/cc"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cxx="${LOCALBASE}/freebsd-sysroot/${FLAVOR:S/_/-/g}/bin/c++"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'linker="${LOCALBASE}/freebsd-sysroot/${FLAVOR:S/_/-/g}/bin/cc"' >> ${WRKSRC}/config.toml
.for _key _util in ar ${AR} ranlib ${RANLIB}
	@bin="$$(which ${_util})"; \
		${ECHO_CMD} "${_key}=\"$$bin\"" >> ${WRKSRC}/config.toml
.endfor
.if ${_RUST_HOST} != ${_RUST_TARGET}
	@${ECHO_CMD} '[target.${_RUST_HOST}]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cc="${CC}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cxx="${CXX}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'linker="${CC}"' >> ${WRKSRC}/config.toml
.endif
	@${ECHO_CMD} '[dist]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'src-tarball=false' >> ${WRKSRC}/config.toml

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} x.py dist --jobs=${MAKE_JOBS_NUMBER}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/rust-bootstrap/${FLAVOR}
	${INSTALL_DATA} ${WRKDIR}/_build/dist/*-${_RUST_ARCH_${FLAVOR}:U${FLAVOR}}-unknown-${OPSYS:tl}${EXTRACT_SUFX} \
		${STAGEDIR}${PREFIX}/rust-bootstrap/${FLAVOR}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} rust-bootstrap -type f >> ${TMPPLIST}

.include <bsd.port.post.mk>
