# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.12.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.xenproject.org/release/xen/${PORTVERSION}/
PKGNAMESUFFIX=	-kernel

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

USES=		cpe gmake python:2.7,build
# LLD 8 changed the behaviour re the placement of orphaned sections, which
# produces a non-bootable Xen kernel:
#
# https://bugs.llvm.org/show_bug.cgi?id=42327
#
# Switch to GNU LD (and NM) until this is resolved.
USE_BINUTILS=	yes
# Ports build environment has ARCH=amd64 set which disables Xen automatic arch
# detection, but amd64 is not a valid arch for Xen. Hardcode x86_64 on the
# command line in order to overwrite the one from the environment.
MAKE_ARGS=	clang=y PYTHON=${PYTHON_CMD} ARCH=x86_64 LD=${LD} NM=${NM}
NO_MTREE=	yes
STRIP=		#
PLIST_FILES=	/boot/xen \
		lib/debug/boot/xen.debug

# Pre-patches for XSA-297 to apply cleanly
EXTRA_PATCHES+=	${PATCHDIR}/0001-x86-tsx-Implement-controls-for-RTM-force-abort-mode.patch:-p1 \
		${PATCHDIR}/0001-x86-msr-Shorten-ARCH_CAPABILITIES_-constants.patch:-p1 \
		${PATCHDIR}/0002-x86-spec-ctrl-Extend-repoline-safey-calcuations-for-.patch:-p1

# Fixes for XSA-297 (MDS)
EXTRA_PATCHES+=	${PATCHDIR}/xsa297-4.12-1.patch:-p1 \
		${PATCHDIR}/xsa297-4.12-2.patch:-p1 \
		${PATCHDIR}/xsa297-4.12-3.patch:-p1 \
		${PATCHDIR}/xsa297-4.12-4.patch:-p1 \
		${PATCHDIR}/xsa297-4.12-5.patch:-p1 \
		${PATCHDIR}/xsa297-4.12-6.patch:-p1 \
		${PATCHDIR}/xsa297-4.12-7.patch:-p1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

.if ${OSVERSION} < 1200074
IGNORE=		only supported on FreeBSD 12.0 or newer
.endif

# The ports native 'build' target cannot be used because it sets
# CFLAGS, and that breaks the Xen build system.
do-build:
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC} build-xen ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}/boot
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/debug/boot/
	${INSTALL_PROGRAM} ${WRKSRC}/xen/xen ${STAGEDIR}/boot
	${INSTALL_DATA} ${WRKSRC}/xen/xen-syms ${STAGEDIR}${PREFIX}/lib/debug/boot/xen.debug

.include <bsd.port.mk>
