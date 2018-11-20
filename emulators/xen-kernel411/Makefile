# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.11.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.xenproject.org/release/xen/${PORTVERSION}/
PKGNAMESUFFIX=	-kernel411

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
EXTRA_PATCHES+=	${FILESDIR}/0001-x86-replace-usage-in-the-linker-script.patch:-p1 \
		${FILESDIR}/0001-x86-efi-move-the-logic-to-detect-PE-build-support.patch:-p1 \
		${FILESDIR}/0002-x86-efi-split-compiler-vs-linker-support.patch:-p1
# Fix PVH Dom0 build with shadow paging
EXTRA_PATCHES+= ${FILESDIR}/0001-x86-pvh-change-the-order-of-the-iommu-initialization.patch:-p1
# XSA-269 (MSR_DEBUGCTL handling) and XSA-273 (L1TF)
# Note that due to the high value of patches needed to fix L1TF the package is
# brought up to the state of the staging-4.11 branch. This can be removed when
# 4.11.1 is released.
EXTRA_PATCHES+= ${FILESDIR}/0001-xen-Port-the-array_index_nospec-infrastructure-from-.patch:-p1 \
		${FILESDIR}/0002-x86-correctly-set-nonlazy_xstate_used-when-loading-f.patch:-p1 \
		${FILESDIR}/0003-x86-spec-ctrl-command-line-handling-adjustments.patch:-p1 \
		${FILESDIR}/0005-mm-page_alloc-correct-first_dirty-calculations-durin.patch:-p1 \
		${FILESDIR}/0006-allow-cpu_down-to-be-called-earlier.patch:-p1 \
		${FILESDIR}/0007-x86-svm-Fixes-and-cleanup-to-svm_inject_event.patch:-p1 \
		${FILESDIR}/0008-cpupools-fix-state-when-downing-a-CPU-failed.patch:-p1 \
		${FILESDIR}/0009-x86-AMD-distinguish-compute-units-from-hyper-threads.patch:-p1 \
		${FILESDIR}/0010-x86-distinguish-CPU-offlining-from-CPU-removal.patch:-p1 \
		${FILESDIR}/0011-x86-possibly-bring-up-all-CPUs-even-if-not-all-are-s.patch:-p1 \
		${FILESDIR}/0012-x86-command-line-option-to-avoid-use-of-secondary-hy.patch:-p1 \
		${FILESDIR}/0013-x86-vmx-Don-t-clobber-dr6-while-debugging-state-is-l.patch:-p1 \
		${FILESDIR}/0014-x86-xstate-Use-a-guests-CPUID-policy-rather-than-all.patch:-p1 \
		${FILESDIR}/0015-x86-xstate-Make-errors-in-xstate-calculations-more-o.patch:-p1 \
		${FILESDIR}/0016-x86-hvm-Disallow-unknown-MSR_EFER-bits.patch:-p1 \
		${FILESDIR}/0017-x86-spec-ctrl-Fix-the-parsing-of-xpti-on-fixed-Intel.patch:-p1 \
		${FILESDIR}/0018-x86-spec-ctrl-Yet-more-fixes-for-xpti-parsing.patch:-p1 \
		${FILESDIR}/0019-x86-vmx-Fix-handing-of-MSR_DEBUGCTL-on-VMExit.patch:-p1 \
		${FILESDIR}/0020-x86-vmx-Defer-vmx_vmcs_exit-as-long-as-possible-in-c.patch:-p1 \
		${FILESDIR}/0021-x86-vmx-API-improvements-for-MSR-load-save-infrastru.patch:-p1 \
		${FILESDIR}/0022-x86-vmx-Internal-cleanup-for-MSR-load-save-infrastru.patch:-p1 \
		${FILESDIR}/0023-x86-vmx-Factor-locate_msr_entry-out-of-vmx_find_msr-.patch:-p1 \
		${FILESDIR}/0024-x86-vmx-Support-remote-access-to-the-MSR-lists.patch:-p1 \
		${FILESDIR}/0025-x86-vmx-Improvements-to-LBR-MSR-handling.patch:-p1 \
		${FILESDIR}/0026-x86-vmx-Pass-an-MSR-value-into-vmx_msr_add.patch:-p1 \
		${FILESDIR}/0027-x86-vmx-Support-load-only-guest-MSR-list-entries.patch:-p1 \
		${FILESDIR}/0028-VMX-fix-vmx_-find-del-_msr-build.patch:-p1 \
		${FILESDIR}/0029-ARM-disable-grant-table-v2.patch:-p1 \
		${FILESDIR}/0030-x86-vtx-Fix-the-checking-for-unknown-invalid-MSR_DEB.patch:-p1 \
		${FILESDIR}/0032-x86-spec-ctrl-Calculate-safe-PTE-addresses-for-L1TF-.patch:-p1 \
		${FILESDIR}/0033-x86-spec-ctrl-Introduce-an-option-to-control-L1TF-mi.patch:-p1 \
		${FILESDIR}/0034-x86-shadow-Infrastructure-to-force-a-PV-guest-into-s.patch:-p1 \
		${FILESDIR}/0035-x86-mm-Plumbing-to-allow-any-PTE-update-to-fail-with.patch:-p1 \
		${FILESDIR}/0036-x86-pv-Force-a-guest-into-shadow-mode-when-it-writes.patch:-p1 \
		${FILESDIR}/0037-x86-spec-ctrl-CPUID-MSR-definitions-for-L1D_FLUSH.patch:-p1 \
		${FILESDIR}/0038-x86-msr-Virtualise-MSR_FLUSH_CMD-for-guests.patch:-p1 \
		${FILESDIR}/0039-x86-spec-ctrl-Introduce-an-option-to-control-L1D_FLU.patch:-p1 \
		${FILESDIR}/0040-x86-Make-spec-ctrl-no-a-global-disable-of-all-mitiga.patch:-p1 \
		${FILESDIR}/0042-x86-write-to-correct-variable-in-parse_pv_l1tf.patch:-p1
# XSA-278: x86: Nested VT-x usable even when disabled
EXTRA_PATCHES+=	${FILESDIR}/xsa278-4.11.patch:-p1
# XSA-{275,276,277,279,280,282}
EXTRA_PATCHES+=	${FILESDIR}/xsa275-4.11-1.patch:-p1 \
		${FILESDIR}/xsa275-4.11-2.patch:-p1 \
		${FILESDIR}/0001-x86-hvm-ioreq-fix-page-referencing.patch:-p1 \
		${FILESDIR}/0002-x86-hvm-ioreq-use-ref-counted-target-assigned-shared.patch:-p1 \
		${FILESDIR}/xsa277.patch:-p1 \
		${FILESDIR}/xsa279.patch:-p1 \
		${FILESDIR}/xsa280-1.patch:-p1 \
		${FILESDIR}/xsa280-4.11-2.patch:-p1 \
		${FILESDIR}/xsa282-4.11-1.patch:-p1 \
		${FILESDIR}/xsa282-2.patch:-p1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

.if ${OSVERSION} < 1200074
IGNORE=		only supported on recent FreeBSD HEAD
.endif

# The ports native 'build' target cannot be used because it sets
# CFLAGS, and that breaks the Xen build system.
do-build:
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC} xen ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}/boot
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/debug/boot/
	${INSTALL_PROGRAM} ${WRKSRC}/xen/xen ${STAGEDIR}/boot
	${INSTALL_DATA} ${FILESDIR}/xen.4th ${STAGEDIR}/boot
	${INSTALL_DATA} ${WRKSRC}/xen/xen-syms ${STAGEDIR}${PREFIX}/lib/debug/boot/xen.debug

.include <bsd.port.mk>
