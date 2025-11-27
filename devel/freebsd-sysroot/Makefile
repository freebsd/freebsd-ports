PORTNAME=	freebsd-sysroot
DISTVERSION=	a2025-11-26
CATEGORIES=	devel
MASTER_SITES=	${_SYSROOT_DIST:@f@https://download.freebsd.org/$f?dummy=/:${FLAVOR}@} \
		LOCAL/rust:${FLAVOR}
PKGNAMEPREFIX=	${FLAVOR:S/_/-/g}-
DISTFILES=	${_SYSROOT_DIST:@f@rust/bootstrap/${FLAVOR}/${_SYSROOT_VER}/${f:T}:${FLAVOR}@}
EXTRACT_ONLY=	${DISTFILES:[1]:S/:${FLAVOR}$$//}

MAINTAINER=	rust@FreeBSD.org
COMMENT=	FreeBSD ${_SYSROOT_VER} ${FLAVOR:S/_/ /} sysroot
WWW=		https://www.FreeBSD.org/

LICENSE=	FREEBSD
LICENSE_NAME=	FreeBSD base licenses
LICENSE_FILE=	${WRKDIR}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FLAVORS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le \
		powerpcspe riscv64
FLAVOR?=	${FLAVORS:[1]}

QA_ENV=		IGNORE_QA_baselibs=1 \
		IGNORE_QA_no_arch=1 \
		IGNORE_QA_proxydeps=1 \
		IGNORE_QA_stripped=1
EXTRACT_AFTER_ARGS=	-C${STAGEDIR}${_SYSROOT} --no-same-permissions \
			${_SYSROOT_INCLUDE:@x@--include=$x@} \
			${_SYSROOT_EXCLUDE:@x@--exclude=$x@}
NO_ARCH=	yes
NO_BUILD=	yes
NO_MTREE=	yes
SUB_FILES=	${exists(${FILESDIR}/${FLAVOR}-c++.in):?${FLAVOR}-c++:} \
		${exists(${FILESDIR}/${FLAVOR}-cc.in):?${FLAVOR}-cc:} c++ cc
SUB_LIST=	FREEBSD_SYSROOT="${_SYSROOT}" \
		FREEBSD_SYSROOT_CC="${CC}" \
		FREEBSD_SYSROOT_CXX="${CXX}" \
		FREEBSD_SYSROOT_LLVM_TRIPLE="${_SYSROOT_LLVM_TRIPLE}"
PLIST=		${.CURDIR}/pkg-plist.${FLAVOR}
PLIST_SUB=	ROOT=${_SYSROOT:S,^${PREFIX}/,,}

_SYSROOT=				${PREFIX}/${PORTNAME}/${FLAVOR:S/_/-/g}
_SYSROOT_VER=				13.5-RELEASE
_SYSROOT_DIST=				${_SYSROOT_DIST_${FLAVOR}}
_SYSROOT_DIST_aarch64=			releases/arm64/${_SYSROOT_VER}/base.txz
_SYSROOT_DIST_armv7=			releases/arm/${FLAVOR}/ISO-IMAGES/${_SYSROOT_VER:S/-/ /:[1]}/FreeBSD-${_SYSROOT_VER}-arm-armv7-GENERICSD.img.xz
_SYSROOT_DIST_amd64=			releases/amd64/${_SYSROOT_VER}/base.txz
_SYSROOT_DIST_i386=			releases/i386/${_SYSROOT_VER}/base.txz
_SYSROOT_DIST_powerpc=			releases/powerpc/powerpc/${_SYSROOT_VER}/base.txz \
					gcc13-13.3.0_3.pkg
_SYSROOT_DIST_powerpc64=		releases/powerpc/powerpc64/${_SYSROOT_VER}/base.txz
_SYSROOT_DIST_powerpc64le=		releases/powerpc/powerpc64le/${_SYSROOT_VER}/base.txz
_SYSROOT_DIST_powerpcspe=		releases/powerpc/powerpcspe/${_SYSROOT_VER}/base.txz
_SYSROOT_DIST_riscv64=			releases/riscv/riscv64/${_SYSROOT_VER}/base.txz
_SYSROOT_INCLUDE=			COPYRIGHT lib/* usr/include/* usr/lib/* \
					usr/libdata/* \
					${_SYSROOT_INCLUDE_${FLAVOR}}
_SYSROOT_EXCLUDE=			lib/geom/* lib/casper/* lib/libalias_* \
					lib/nvmecontrol/* usr/include/private/* \
					usr/lib/pam_* usr/lib/snmp_* \
					usr/lib/libprivate* *_p.a \
					${_SYSROOT_EXCLUDE_${FLAVOR}}
_SYSROOT_EXCLUDE_armv7=			usr/lib/debug/*
_SYSROOT_ARCH_amd64=			x86_64
_SYSROOT_ARCH_i386=			i686
_SYSROOT_LLVM_TRIPLE=			${_SYSROOT_LLVM_TRIPLE_${FLAVOR}:U${_SYSROOT_ARCH_${FLAVOR}:U${FLAVOR}}-unknown-${OPSYS:tl}}
_SYSROOT_LLVM_TRIPLE_aarch64=		aarch64-unknown-freebsd13.5
_SYSROOT_LLVM_TRIPLE_armv7=		armv7-unknown-freebsd13.5-gnueabihf
_SYSROOT_LLVM_TRIPLE_powerpc=		powerpc-unknown-freebsd13.5 # secure-plt
_SYSROOT_LLVM_TRIPLE_powerpc64=		powerpc64-unknown-freebsd13.5 # elfv2

.if make(distclean) || make(makesum)
MASTER_SITES:=	${FLAVORS:O:@_flavor@${:!${SETENV} FLAVOR=${_flavor} ${MAKE} -VMASTER_SITES!}@}
DISTFILES:=	${FLAVORS:O:@_flavor@${:!${SETENV} FLAVOR=${_flavor} ${MAKE} -V'DISTFILES'!}@}
.endif

# to be removed if the port ever switched to base.txz for armv7
.if ${FLAVOR} == armv7
BROKEN_powerpc=	little-endian UFS fails to be read on big-endian architectures
BROKEN_powerpcspe=	little-endian UFS fails to be read on big-endian architectures
BROKEN_powerpc64=	little-endian UFS fails to be read on big-endian architectures
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		is only for FreeBSD
.endif

pre-extract:
	@${MKDIR} ${STAGEDIR}${_SYSROOT}

# No base.txz for armv7 so extract what we need from the available *.img files
.if ${FLAVOR} == armv7
# for label offset: unxz -c $img | file -
# for UFS slice offset: unxz -c $img | dd skip=$label_offset count=8192 >label; bsdlabel -f label; rm label
# skip = label_offset + slice_offset
# check if detected as UFS: unxz -c $img | dd skip=$skip | file -
do-extract:
	@unxz -c ${_DISTDIR}/${EXTRACT_ONLY} | \
		dd skip=104576 >${WRKDIR}/base.img
	@${MKDIR} ${WRKDIR}/base
	@cd ${WRKDIR}/base; \
		dump -0f - ${WRKDIR}/base.img | \
		restore -rf -
	@${RM} ${WRKDIR}/base.img
	@chflags -R noschg ${WRKDIR}/base
	@${TAR} -C${WRKDIR}/base -cf - . | \
		${TAR} -xf - ${EXTRACT_AFTER_ARGS}
.endif

post-extract:
.if ${FLAVOR} == powerpc
	cd ${EXTRACT_WRKDIR} && \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/rust/bootstrap/${FLAVOR}/${_SYSROOT_VER}/${_SYSROOT_DIST_${FLAVOR}:[2]} \
		-C${STAGEDIR}${_SYSROOT} /usr/local/lib/gcc13
.endif
	@${FIND} ${STAGEDIR}${_SYSROOT} -type d -empty -delete
	@${MV} ${STAGEDIR}${_SYSROOT}/COPYRIGHT ${WRKDIR}

do-install:
.if ${FLAVOR} == powerpc
	@${RLN} ${STAGEDIR}${_SYSROOT}/usr/local/lib/gcc13/libatomic.so \
		${STAGEDIR}${_SYSROOT}/usr/lib/libatomic.so
.endif
	@${MKDIR} ${STAGEDIR}${_SYSROOT}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${exists(${FILESDIR}/${FLAVOR}-cc.in):?${FLAVOR}-cc:cc} \
		${STAGEDIR}${_SYSROOT}/bin/cc
	${INSTALL_SCRIPT} ${WRKDIR}/${exists(${FILESDIR}/${FLAVOR}-c++.in):?${FLAVOR}-c++:c++} \
		${STAGEDIR}${_SYSROOT}/bin/c++
	@${CAT} ${STAGEDIR}${_SYSROOT}/bin/c*
# sanity check cross compilers.
	@${PRINTF} '#include <stdio.h>\nint main(){return printf("hello\\n");}' | \
		${SETENV} FREEBSD_SYSROOT=${STAGEDIR}${_SYSROOT} ${STAGEDIR}${_SYSROOT}/bin/cc \
		-o ${WRKDIR}/test-c -xc -
# produce some useful info for the build logs like what release/arch test-c is compiled for
	@cd ${WRKDIR} && \
		${FILE} test-c && \
		${READELF} -A test-c
	@${PRINTF} '#include <iostream>\nint main(){std::cout<<"hello"<<std::endl;return 0;}' | \
		${SETENV} FREEBSD_SYSROOT=${STAGEDIR}${_SYSROOT} ${STAGEDIR}${_SYSROOT}/bin/c++ \
		-o ${WRKDIR}/test-c++ -xc++ -

.include <bsd.port.post.mk>
