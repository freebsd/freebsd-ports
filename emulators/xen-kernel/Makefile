PORTNAME=	xen
PORTVERSION=	4.16.0
PORTREVISION=	0
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.xenproject.org/release/xen/${PORTVERSION}/
PKGNAMESUFFIX=	-kernel

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

USES=		cpe gmake python:build bison

# Ports build environment has ARCH=amd64 set which disables Xen automatic arch
# detection, but amd64 is not a valid arch for Xen. Hardcode x86_64 on the
# command line in order to overwrite the one from the environment.
MAKE_ARGS=	clang=y PYTHON=${PYTHON_CMD} ARCH=x86_64
NO_MTREE=	yes
STRIP=		#
PLIST_FILES=	/boot/xen \
		/boot/xen-debug \
		lib/debug/boot/xen.debug \
		lib/debug/boot/xen-debug.debug

# XSA-395
EXTRA_PATCHES+=	${PATCHDIR}/xsa395.patch:-p1

# XSA-398
EXTRA_PATCHES+=	${PATCHDIR}/0001-x86-spec-ctrl-Drop-use_spec_ctrl-boolean.patch:-p1 \
		${PATCHDIR}/0002-x86-spec-ctrl-Introduce-new-has_spec_ctrl-boolean.patch:-p1 \
		${PATCHDIR}/xsa398-4.16-6-x86-spec-ctrl-Cease-using-thunk-lfence-on-AMD.patch:-p1

# Add retpoline support for clang builds
EXTRA_PATCHES+=	${PATCHDIR}/0001-x86-retpoline-split-retpoline-compiler-support-into-.patch:-p1 \
		${PATCHDIR}/0002-x86-clang-add-retpoline-support.patch:-p1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

# The ports native 'build' target cannot be used because it sets
# CFLAGS, and that breaks the Xen build system.
#
# Build both a production and a debug hypervisor.
do-build:
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC} build-xen ${MAKE_ARGS} debug=y
	cp ${WRKSRC}/xen/xen ${WRKSRC}/xen/xen-debug
	cp ${WRKSRC}/xen/xen-syms ${WRKSRC}/xen/xen-debug-syms
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC} clean-xen ${MAKE_ARGS}
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC} build-xen ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}/boot
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/debug/boot/
	${INSTALL_PROGRAM} ${WRKSRC}/xen/xen ${STAGEDIR}/boot
	${INSTALL_DATA} ${WRKSRC}/xen/xen-syms ${STAGEDIR}${PREFIX}/lib/debug/boot/xen.debug
	${INSTALL_PROGRAM} ${WRKSRC}/xen/xen-debug ${STAGEDIR}/boot
	${INSTALL_DATA} ${WRKSRC}/xen/xen-debug-syms ${STAGEDIR}${PREFIX}/lib/debug/boot/xen-debug.debug

.include <bsd.port.mk>
