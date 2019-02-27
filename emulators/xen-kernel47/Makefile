# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.7.2
PORTREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.xenproject.org/release/xen/${PORTVERSION}/
PKGNAMESUFFIX=	-kernel47

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

DEPRECATED=	This port is about to be removed, please update to a newer Xen version
EXPIRATION_DATE=2019-07-01

USES=		cpe gmake python:2.7,build

# We need to use ld from ports because the version in base doesn't
# support the '--build-id' switch that's needed for live hypervisor
# hot-patching. Once the ld version in base supports this option the
# dependency can be removed.
#
# GNU objcopy is used instead of elftc objcopy because of bug #533:
# https://sourceforge.net/p/elftoolchain/tickets/533/
# Once this is solved we should be able to switch to elfcopy.
#
# And finally we also need to use nm from binutils because the one
# from base cannot deal with i386pep binary files which is the format
# of the Xen EFI image (note that FreeBSD cannot yet boot as Dom0 from EFI,
# but the image is built anyway). This is reported to elftc as bug #534:
# https://sourceforge.net/p/elftoolchain/tickets/534/
MAKE_ARGS=	clang=y PYTHON=${PYTHON_CMD} LD="${LD}" OBJCOPY="${OBJCOPY}" \
		NM="${NM}"
USE_BINUTILS=	yes
NO_MTREE=	yes
STRIP=		#
PLIST_FILES=	/boot/xen \
		/boot/xen.4th
EXTRA_PATCHES=	${FILESDIR}/0001-xen-logdirty-prevent-preemption-if-finished.patch:-p1 \
		${FILESDIR}/0002-xen-rework-paging_log_dirty_op-to-work-with-hvm-gues.patch:-p1 \
		${FILESDIR}/kconf_arch.patch:-p1 \
		${FILESDIR}/0001-x86-drop-unneeded-__packed-attributes.patch:-p1 \
		${FILESDIR}/0002-build-clang-fix-XSM-dummy-policy-when-using-clang-4..patch:-p1 \
		${FILESDIR}/xsa212.patch:-p1 \
		${FILESDIR}/xsa213-4.7.patch:-p1 \
		${FILESDIR}/xsa214.patch:-p1 \
		${FILESDIR}/xsa215.patch:-p1 \
		${FILESDIR}/xsa217.patch:-p1 \
		${FILESDIR}/0001-IOMMU-handle-IOMMU-mapping-and-unmapping-failures.patch:-p1 \
		${FILESDIR}/0002-gnttab-fix-unmap-pin-accounting-race.patch:-p1 \
		${FILESDIR}/0003-gnttab-Avoid-potential-double-put-of-maptrack-entry.patch:-p1 \
		${FILESDIR}/0004-gnttab-correct-maptrack-table-accesses.patch:-p1 \
		${FILESDIR}/xsa219-4.8.patch:-p1 \
		${FILESDIR}/xsa220-4.7.patch:-p1 \
		${FILESDIR}/xsa221.patch:-p1 \
		${FILESDIR}/xsa222-1-4.7.patch:-p1 \
		${FILESDIR}/xsa222-2-4.7.patch:-p1 \
		${FILESDIR}/0001-gnttab-Fix-handling-of-dev_bus_addr-during-unmap.patch:-p1 \
		${FILESDIR}/0002-gnttab-never-create-host-mapping-unless-asked-to.patch:-p1 \
		${FILESDIR}/0003-gnttab-correct-logic-to-get-page-references-during-m.patch:-p1 \
		${FILESDIR}/0004-gnttab-__gnttab_unmap_common_complete-is-all-or-noth.patch:-p1 \
		${FILESDIR}/xsa226-4.7.patch:-p1 \
		${FILESDIR}/xsa227.patch:-p1 \
		${FILESDIR}/xsa228-4.8.patch:-p1 \
		${FILESDIR}/xsa230.patch:-p1 \
		${FILESDIR}/xsa231-4.7.patch:-p1 \
		${FILESDIR}/xsa232.patch:-p1 \
		${FILESDIR}/xsa233.patch:-p1 \
		${FILESDIR}/xsa234-4.8.patch:-p1 \
		${FILESDIR}/0001-x86-dont-allow-MSI-pIRQ-mapping-on-unowned-device.patch:-p1 \
		${FILESDIR}/0002-x86-enforce-proper-privilege-when-mapping-pIRQ-s.patch:-p1 \
		${FILESDIR}/0003-x86-MSI-disallow-redundant-enabling.patch:-p1 \
		${FILESDIR}/0004-x86-IRQ-conditionally-preserve-irq-pirq-mapping-on-error.patch:-p1 \
		${FILESDIR}/0005-x86-FLASK-fix-unmap-domain-IRQ-XSM-hook.patch:-p1 \
		${FILESDIR}/xsa238.patch:-p1 \
		${FILESDIR}/xsa239.patch:-p1 \
		${FILESDIR}/0001-x86-limit-linear-page-table-use-to-a-single-level.patch:-p1 \
		${FILESDIR}/0002-x86-mm-Disable-PV-linear-pagetables-by-default.patch:-p1 \
		${FILESDIR}/xsa241-4.8.patch:-p1 \
		${FILESDIR}/xsa242-4.9.patch:-p1 \
		${FILESDIR}/xsa243-4.7.patch:-p1 \
		${FILESDIR}/xsa244-4.7.patch:-p1 \
		${FILESDIR}/xsa236-4.9.patch:-p1 \
		${FILESDIR}/0001-x86-compat-fix-compilation-errors-with-clang-6.patch:-p1 \
		${FILESDIR}/xsa246-4.7.patch:-p1 \
		${FILESDIR}/0001-p2m-Always-check-to-see-if-removing-a-p2m-entry-actu.patch:-p1 \
		${FILESDIR}/0002-p2m-Check-return-value-of-p2m_set_entry-when-decreas.patch:-p1 \
		${FILESDIR}/xsa248-4.8.patch:-p1 \
		${FILESDIR}/xsa249.patch:-p1 \
		${FILESDIR}/xsa250.patch:-p1 \
		${FILESDIR}/xsa251-4.8.patch:-p1 \
		${FILESDIR}/0001-x86-entry-Remove-support-for-partial-cpu_user_regs-f.patch:-p1 \
		${FILESDIR}/0001-x86-mm-Always-set-_PAGE_ACCESSED-on-L4e-updates.patch:-p1 \
		${FILESDIR}/0001-x86-Meltdown-band-aid-against-malicious-64-bit-PV-gu.patch:-p1 \
		${FILESDIR}/0002-x86-allow-Meltdown-band-aid-to-be-disabled.patch:-p1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

pre-build:
	${MAKE_CMD} -C ${WRKSRC}/xen defconfig ${MAKE_ARGS}
	# Enable hypervisor hot-patching.
	echo 'CONFIG_XSPLICE=y' >> ${WRKSRC}/xen/.config
	echo 'CONFIG_FAST_SYMBOL_LOOKUP=y' >> ${WRKSRC}/xen/.config

# The ports native 'build' target cannot be used because it sets
# CFLAGS, and that breaks the Xen build system.
do-build:
	${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC}/xen build ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}/boot
	${INSTALL_PROGRAM} ${WRKSRC}/xen/xen ${STAGEDIR}/boot
	${INSTALL_DATA} ${FILESDIR}/xen.4th ${STAGEDIR}/boot

.include <bsd.port.mk>
