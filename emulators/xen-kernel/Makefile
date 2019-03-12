# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.11.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.xenproject.org/release/xen/${PORTVERSION}/
PKGNAMESUFFIX=	-kernel

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

USES=		cpe gmake python:2.7,build
# Ports build environment has ARCH=amd64 set which disables Xen automatic arch
# detection, but amd64 is not a valid arch for Xen. Hardcode x86_64 on the
# command line in order to overwrite the one from the environment.
MAKE_ARGS=	clang=y PYTHON=${PYTHON_CMD} ARCH=x86_64
NO_MTREE=	yes
STRIP=		#
PLIST_FILES=	/boot/xen \
		/boot/xen.4th \
		lib/debug/boot/xen.debug

# IOMMU fixes
EXTRA_PATCHES=	${FILESDIR}/0001-pci-treat-class-0-devices-as-endpoints.patch:-p1
# vPCI MSI fixes
EXTRA_PATCHES+=	${FILESDIR}/0001-vpci-msi-split-code-to-bind-pirq.patch:-p1 \
		${FILESDIR}/0002-vpci-msi-fix-update-of-bound-MSI-interrupts.patch:-p1
# Add extra RAM regions to Dom0 memory map as UNUSABNLE
EXTRA_PATCHES+=	${FILESDIR}/0001-x86-dom0-add-extra-RAM-regions-as-UNUSABLE-for-PVH-m.patch:-p1
# MTRR guest setup for PVH
EXTRA_PATCHES+=	${FILESDIR}/0001-x86-mtrr-introduce-mask-to-get-VCNT-from-MTRRcap-MSR.patch:-p1 \
		${FILESDIR}/0001-x86-HVM-improve-MTRR-load-checks.patch:-p1 \
		${FILESDIR}/0002-x86-mtrr-split-enabled-field-into-two-boolean-flags.patch:-p1 \
		${FILESDIR}/0003-hvm-mtrr-add-emacs-local-variables-block-with-format.patch:-p1 \
		${FILESDIR}/0004-hvm-mtrr-use-the-hardware-number-of-variable-ranges-.patch:-p1 \
		${FILESDIR}/0005-hvm-mtrr-copy-hardware-state-for-Dom0.patch:-p1 \
		${FILESDIR}/0006-libxc-pvh-set-default-MTRR-type-to-write-back.patch:-p1 \
		${FILESDIR}/0007-docs-pvh-document-initial-MTRR-state.patch:-p1
# Build with lld (LLVM linker)
EXTRA_PATCHES+=	${FILESDIR}/0001-x86-replace-usage-in-the-linker-script.patch:-p1
# Fix PVH Dom0 build with shadow paging
EXTRA_PATCHES+= ${FILESDIR}/0001-x86-pvh-change-the-order-of-the-iommu-initialization.patch:-p1
# Forward dom0 lapic EOIs to underlying hardware
EXTRA_PATCHES+=	${FILESDIR}/0001-x86-dom0-propagate-PVH-vlapic-EOIs-to-hardware.patch:-p1
# Fix deadlock in IO-APIC gsi mapping
EXTRA_PATCHES+=	${FILESDIR}/0001-pvh-dom0-fix-deadlock-in-GSI-mapping.patch:-p1
# Fix for migration/save
EXTRA_PATCHES+=	${FILESDIR}/0001-x86-mm-locks-remove-trailing-whitespace.patch:-p1 \
		${FILESDIR}/0002-x86-mm-locks-convert-some-macros-to-inline-functions.patch:-p1 \
		${FILESDIR}/0003-x86-mm-locks-apply-a-bias-to-lock-levels-for-control.patch:-p1

# XSA-284
EXTRA_PATCHES+=	${FILESDIR}/xsa284.patch:-p1
# XSA-287
EXTRA_PATCHES+=	${FILESDIR}/xsa287-4.11.patch:-p1
# XSA-290
EXTRA_PATCHES+=	${FILESDIR}/xsa290-4.11-1.patch:-p1 \
		${FILESDIR}/xsa290-4.11-2.patch:-p1
# XSA-292
EXTRA_PATCHES+=	${FILESDIR}/xsa292.patch:-p1
# XSA-293
EXTRA_PATCHES+=	${FILESDIR}/xsa293-4.11-1.patch:-p1 \
		${FILESDIR}/xsa293-4.11-2.patch:-p1
# XSA-294
EXTRA_PATCHES+=	${FILESDIR}/xsa294-4.11.patch:-p1

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
	${INSTALL_DATA} ${FILESDIR}/xen.4th ${STAGEDIR}/boot
	${INSTALL_DATA} ${WRKSRC}/xen/xen-syms ${STAGEDIR}${PREFIX}/lib/debug/boot/xen.debug

.include <bsd.port.mk>
