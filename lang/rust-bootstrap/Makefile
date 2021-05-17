# Once the bootstraps are available on pkg.FreeBSD.org run sync.sh
# to upload them to ~/public_distfiles on freefall in preparation
# for the next lang/rust update.
PORTNAME=	rust
PORTVERSION=	1.52.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES?=	https://static.rust-lang.org/dist/:rust \
		LOCAL/tobik/rust:${FLAVOR} \
		https://download.freebsd.org/ftp/${_RUST_FBSD_SUBDIR_${FLAVOR}}/:${FLAVOR}
#		http://pkg.freebsd.org/FreeBSD:12:powerpc64/quarterly/All/gcc9-9.3.0_1.txz?dummy=/:powerpc64_gcc
PKGNAMESUFFIX=	-bootstrap
DISTNAME=	${PORTNAME}c-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:rust \
		${_RUST_FBSD_DIST_${FLAVOR}:@f@bootstrap/$f:${FLAVOR}@}
DIST_SUBDIR=	rust

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Create bootstrap compilers for building lang/rust

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	untested on other archs

BUILD_DEPENDS=	cmake:devel/cmake \
		gmake:devel/gmake \
		rust>=${PORTVERSION}:lang/rust

FLAVORS=	aarch64 amd64 armv6 armv7 i386 powerpc64_elfv1 powerpc64_elfv2 \
		powerpc64le powerpc
FLAVOR?=	${FLAVORS:[1]}

aarch64_PKGNAMEPREFIX=		aarch64-
aarch64_BUILD_DEPENDS=		llvm90>0:devel/llvm90
amd64_PKGNAMEPREFIX=		amd64-
armv6_PKGNAMEPREFIX=		armv6-
armv7_PKGNAMEPREFIX=		armv7-
i386_PKGNAMEPREFIX=		i386-
powerpc64_elfv1_PKGNAMEPREFIX=	powerpc64-elfv1-
powerpc64_elfv1_BUILD_DEPENDS=	powerpc64-gcc9>0:devel/freebsd-gcc9@powerpc64
powerpc64_elfv2_PKGNAMEPREFIX=	powerpc64-elfv2-
powerpc64le_PKGNAMEPREFIX=	powerpc64le-
powerpc_PKGNAMEPREFIX=		powerpc-
powerpc_BUILD_DEPENDS=		powerpc-binutils>0:devel/binutils@powerpc

USES=		ninja:build perl5 python:3.6+,build tar:xz
.if ${FLAVOR} == powerpc64_elfv1
USE_GCC=	9:build
.endif
# for openssl-src crate
USE_PERL5=	build
.if ${FLAVOR} == aarch64
CC=		clang90
CXX=		clang++90
.endif
PATCHDIR=	${.CURDIR}/../rust/files
# Resulting packages are not specific to amd64
NO_ARCH=	yes

_RUST_FBSD_DIST_aarch64=		FreeBSD-${_RUST_FBSD_VER}-arm64${EXTRACT_SUFX}
_RUST_FBSD_DIST_amd64=			FreeBSD-${_RUST_FBSD_VER}-amd64${EXTRACT_SUFX}
# base.txz for armv* created from WANDBOARD images as there seem
# to be no generic base.txz for it.
_RUST_FBSD_DIST_armv6=			FreeBSD-${_RUST_FBSD_VER}-arm-armv6${EXTRACT_SUFX}
_RUST_FBSD_DIST_armv7=			FreeBSD-${_RUST_FBSD_VER}-arm-armv7${EXTRACT_SUFX}
_RUST_FBSD_DIST_i386=			FreeBSD-${_RUST_FBSD_VER}-i386${EXTRACT_SUFX}
_RUST_FBSD_DIST_powerpc64_elfv1=	FreeBSD-${_RUST_FBSD_VER}-powerpc64-elfv1${EXTRACT_SUFX} \
					FreeBSD-${_RUST_FBSD_VER}-powerpc64-elfv1-gcc9-9.3.0${EXTRACT_SUFX}
_RUST_FBSD_DIST_powerpc64_elfv2=	FreeBSD-${_RUST_FBSD_VER}-powerpc64-elfv2-v1300123${EXTRACT_SUFX}
_RUST_FBSD_DIST_powerpc64le=		FreeBSD-${_RUST_FBSD_VER}-powerpc64le-r366300${EXTRACT_SUFX}
_RUST_FBSD_DIST_powerpc=		FreeBSD-${_RUST_FBSD_VER}-powerpc${EXTRACT_SUFX}
_RUST_FBSD_VER=				${_RUST_FBSD_VER_${FLAVOR}:U11.4-RELEASE}
_RUST_FBSD_VER_aarch64=			12.2-RELEASE
_RUST_FBSD_VER_armv7=			12.2-RELEASE
_RUST_FBSD_VER_powerpc64_elfv1=		12.2-RELEASE
_RUST_FBSD_VER_powerpc64_elfv2=		13.0-CURRENT
_RUST_FBSD_VER_powerpc64le=		13.0-CURRENT
_RUST_FBSD_VER_powerpc=			13.0-RELEASE
_RUST_FBSD_SUBDIR_aarch64=		releases/arm64/${_RUST_FBSD_VER}/base.txz?dummy=
_RUST_FBSD_SUBDIR_amd64=		releases/amd64/${_RUST_FBSD_VER}/base.txz?dummy=
_RUST_FBSD_SUBDIR_i386=			releases/i386/${_RUST_FBSD_VER}/base.txz?dummy=
_RUST_FBSD_SUBDIR_powerpc64_elfv1=	releases/powerpc/powerpc64/${_RUST_FBSD_VER}/base.txz?dummy=
_RUST_FBSD_SUBDIR_powerpc64_elfv2=	snapshots/powerpc/powerpc64/${_RUST_FBSD_VER}/base.txz?dummy=
_RUST_FBSD_SUBDIR_powerpc64le=		snapshots/powerpc/powerpc64le/${_RUST_FBSD_VER}/base.txz?dummy=
_RUST_FBSD_SUBDIR_powerpc=		releases/powerpc/powerpc/${_RUST_FBSD_VER}/base.txz?dummy=

_CARGO_VENDOR_DIR=			${WRKSRC}/vendor
_RUST_ARCH_amd64=			x86_64
_RUST_ARCH_i386=			i686
_RUST_ARCH_powerpc64_elfv1=		powerpc64
_RUST_ARCH_powerpc64_elfv2=		powerpc64
_RUST_ARCH_powerpc64le=			powerpc64le
_RUST_ARCH_powerpc=			powerpc
_RUST_HOST=				${_RUST_ARCH_${ARCH}:U${ARCH}}-unknown-${OPSYS:tl}
_RUST_TARGET=				${_RUST_ARCH_${FLAVOR}:U${FLAVOR}}-unknown-${OPSYS:tl}
_RUST_LLVM_TARGET=			${_RUST_LLVM_TARGET_${FLAVOR}}
_RUST_LLVM_TARGET_aarch64=		AArch64
_RUST_LLVM_TARGET_amd64=		X86
_RUST_LLVM_TARGET_armv6=		ARM
_RUST_LLVM_TARGET_armv7=		ARM
_RUST_LLVM_TARGET_i386=			X86
_RUST_LLVM_TARGET_powerpc64_elfv1=	PowerPC
_RUST_LLVM_TARGET_powerpc64_elfv2=	PowerPC
_RUST_LLVM_TARGET_powerpc64le=		PowerPC
_RUST_LLVM_TARGET_powerpc=		PowerPC
_RUST_LLVM_TRIPLE=			${_RUST_LLVM_TRIPLE_${FLAVOR}:U${_RUST_TARGET}}
_RUST_LLVM_TRIPLE_armv6=		armv6-gnueabihf-freebsd
_RUST_LLVM_TRIPLE_armv7=		armv7-gnueabihf-freebsd
_RUST_LLVM_TRIPLE_powerpc=		powerpc-unknown-freebsd13.0 # secure-plt

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=	is only for FreeBSD
.elif ${OSVERSION} < 1200502
IGNORE=	will not build on 12.0 due to old toolchain; 11.x untested
.endif
.if ${FLAVOR} == powerpc64le && ${OSVERSION} < 1300116
IGNORE=	will not build on 12.x due to old system
.endif

.if exists(${PATCHDIR}/${FLAVOR:S/_/-/})
EXTRA_PATCHES+=	${PATCHDIR}/${FLAVOR:S/_/-/}
.endif

.if make(distclean) || make(makesum)
MASTER_SITES:=	${FLAVORS:@_flavor@${:!${SETENV} FLAVOR=${_flavor} ${MAKE} -VMASTER_SITES!}@:O:u}
.export MASTER_SITES
DISTFILES:=	${DISTFILES:M*\:rust} \
		${FLAVORS:O:@_flavor@${:!${SETENV} FLAVOR=${_flavor} ${MAKE} -V'DISTFILES:N*\:rust'!}@}
.endif

post-patch:
# Disable vendor checksums
	@${REINPLACE_CMD} 's,"files":{[^}]*},"files":{},' \
		${_CARGO_VENDOR_DIR}/*/.cargo-checksum.json
.if ${FLAVOR} == powerpc64_elfv1
	@${REINPLACE_CMD} -e 's,"c++","stdc++",g' \
		${WRKSRC}/compiler/rustc_llvm/build.rs
	@${REINPLACE_CMD} -e 's,%CC%,${CC},g' \
		-e 's,%WRKDIR%,${WRKDIR},g' \
		${WRKSRC}/compiler/rustc_llvm/build.rs \
		${WRKSRC}/src/bootstrap/native.rs
.endif

do-configure:
# Check that the running kernel has COMPAT_FREEBSD11 required by lang/rust post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh
	@${ECHO_CMD} 'changelog-seen=2' > ${WRKSRC}/config.toml
	@${ECHO_CMD} '[build]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'vendor=true' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'extended=false' >> ${WRKSRC}/config.toml
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
	@${ECHO_CMD} 'link-shared=false' >> ${WRKSRC}/config.toml
.if ${FLAVOR} == powerpc64_elfv1
	@${ECHO_CMD} 'static-libstdcpp=true' >> ${WRKSRC}/config.toml
.endif
.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
	@${ECHO_CMD} 'ccache="${CCACHE_BIN}"' >> ${WRKSRC}/config.toml
.else
	@${ECHO_CMD} 'ccache=false' >> ${WRKSRC}/config.toml
.endif
# https://github.com/rust-lang/rust/pull/72696#issuecomment-641517185
	@${ECHO_CMD} 'ldflags="-lz"' >> ${WRKSRC}/config.toml
# we need to make sure to always build llvm with X86 support to get a
# host compiler that can build the host->target compiler
	@${ECHO_CMD} 'targets="${_RUST_LLVM_TARGET};X86"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} '[target.${_RUST_TARGET}]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cc="${WRKDIR}/${_RUST_TARGET}-cc"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cxx="${WRKDIR}/${_RUST_TARGET}-c++"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'linker="${WRKDIR}/${_RUST_TARGET}-cc"' >> ${WRKSRC}/config.toml
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
.if ${FLAVOR} == powerpc64_elfv1
	@${RLN} ${WRKDIR}${LOCALBASE}/lib/gcc9/libstdc++.a ${WRKDIR}/usr/lib/libstdc++.a
	@${RLN} ${WRKDIR}${LOCALBASE}/lib/gcc9/libstdc++.a ${WRKDIR}/usr/lib/libc++.a
	@gcc="$$(${ECHO_CMD} ${LOCALBASE}/bin/${_RUST_TARGET}*[0-9]-gcc9)"; \
		${PRINTF} '#!/bin/sh\nexec %s --sysroot=${WRKDIR} -Wl,-rpath=${LOCALBASE}/lib/gcc9 -L${WRKDIR}${LOCALBASE}/lib/gcc9 "$$@"\n' "$${gcc}" \
			> ${WRKDIR}/${_RUST_TARGET}-cc
	@gcc="$$(${ECHO_CMD} ${LOCALBASE}/bin/${_RUST_TARGET}*[0-9]-g++9)"; \
		cxxinc="/$$(cd ${WRKDIR} && ${ECHO_CMD} ${LOCALBASE:S,^/,,}/lib/gcc9/include/c++/powerpc64-*)"; \
		${PRINTF} '#!/bin/sh\nexec %s --sysroot=${WRKDIR} -isystem=${LOCALBASE}/lib/gcc9/include/c++ -isystem=%s -Wl,-rpath=${LOCALBASE}/lib/gcc9 -L${WRKDIR}${LOCALBASE}/lib/gcc9 "$$@"\n' "$${gcc}" "$${cxxinc}" \
			> ${WRKDIR}/${_RUST_TARGET}-c++
.elif ${FLAVOR} == powerpc64_elfv2
	@${PRINTF} '#!/bin/sh\nexec ${CC} --sysroot=${WRKDIR} -mabi=elfv2 --target=${_RUST_LLVM_TRIPLE} "$$@"\n' \
		> ${WRKDIR}/${_RUST_TARGET}-cc
	@${PRINTF} '#!/bin/sh\nexec ${CXX} --sysroot=${WRKDIR} -mabi=elfv2 --target=${_RUST_LLVM_TRIPLE} -stdlib=libc++ "$$@"\n' \
		> ${WRKDIR}/${_RUST_TARGET}-c++
.elif ${FLAVOR} == powerpc
	@bfd="$$(${ECHO_CMD} ${LOCALBASE}/bin/${_RUST_TARGET}*[0-9]-ld.bfd)"; \
		${PRINTF} '#!/bin/sh\nexec ${CC} --sysroot=${WRKDIR} --target=${_RUST_LLVM_TRIPLE} -Wno-unused-command-line-argument -fuse-ld=%s "$$@"\n' "$${bfd}" \
			> ${WRKDIR}/${_RUST_TARGET}-cc; \
		${PRINTF} '#!/bin/sh\nexec ${CXX} --sysroot=${WRKDIR} --target=${_RUST_LLVM_TRIPLE} -Wno-unused-command-line-argument -fuse-ld=%s "$$@"\n' "$${bfd}" \
			> ${WRKDIR}/${_RUST_TARGET}-c++
.else
	@${PRINTF} '#!/bin/sh\nexec ${CC} --sysroot=${WRKDIR} --target=${_RUST_LLVM_TRIPLE} "$$@"\n' \
		> ${WRKDIR}/${_RUST_TARGET}-cc
	@${PRINTF} '#!/bin/sh\nexec ${CXX} --sysroot=${WRKDIR} --target=${_RUST_LLVM_TRIPLE} -stdlib=libc++ "$$@"\n' \
		> ${WRKDIR}/${_RUST_TARGET}-c++
.endif
	@${CHMOD} +x ${WRKDIR}/${_RUST_TARGET}-c*
# sanity check cross compilers.  we cannot execute the result but
# at least check that it can link a simple program before going further.
	@${PRINTF} '#include <stdio.h>\nint main(){return printf("hello\\n");}' | ${WRKDIR}/${_RUST_TARGET}-cc -o ${WRKDIR}/test-c -xc -
# produce some useful info for the build logs like what release/arch test-c is compiled for
	@cd ${WRKDIR} && ${FILE} test-c && ${READELF} -A test-c
	@${PRINTF} '#include <iostream>\nint main(){std::cout<<"hello"<<std::endl;return 0;}' | ${WRKDIR}/${_RUST_TARGET}-c++ -o ${WRKDIR}/test-c++ -xc++ -

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} x.py dist --jobs=${MAKE_JOBS_NUMBER} \
		cargo src/librustc library/std

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/rust-bootstrap/${FLAVOR}
	${INSTALL_DATA} ${WRKSRC}/build/dist/*-${_RUST_ARCH_${FLAVOR}:U${FLAVOR}}-unknown-${OPSYS:tl}${EXTRACT_SUFX} \
		${STAGEDIR}${PREFIX}/rust-bootstrap/${FLAVOR}
.if ${FLAVOR:Mpowerpc64_*}
	@cd ${STAGEDIR}${PREFIX}/rust-bootstrap/${FLAVOR} && for f in *${EXTRACT_SUFX}; do \
		${MV} $$f $${f%%${EXTRACT_SUFX}}-${FLAVOR:S/_/ /:[2]}${EXTRACT_SUFX}; \
	done
.endif
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} rust-bootstrap -type f >> ${TMPPLIST}

.include <bsd.port.post.mk>
