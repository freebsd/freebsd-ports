# $FreeBSD$

PORTNAME=	xen
PKGNAMESUFFIX=	-kernel
PORTVERSION=	4.5.2
PORTREVISION=   2
CATEGORIES=	emulators
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

USES=		cpe gmake python:build
MAKE_ARGS=	HOSTCC="${CC}" CC="${CC}" PYTHON=${PYTHON_CMD} \
		NM="${NM}" LD="${LD}"
USE_GCC=	yes
NO_MTREE=	yes
PLIST_FILES=	/boot/xen \
		/boot/xen.4th
ALL_TARGET=	build
STRIP=		#
WRKSRC_SUBDIR=	xen
EXTRA_PATCHES=	${FILESDIR}/0001-introduce-a-helper-to-allocate-non-contiguous-memory.patch:-p2 \
		${FILESDIR}/0002-vmap-avoid-hitting-an-ASSERT-with-vfree-NULL.patch:-p2 \
		${FILESDIR}/0003-x86-shadow-fix-shadow_track_dirty_vram-to-work-on-hv.patch:-p2 \
		${FILESDIR}/0004-x86-hap-make-hap_track_dirty_vram-use-non-contiguous.patch:-p2 \
		${FILESDIR}/0005-x86-rework-paging_log_dirty_op-to-work-with-hvm-gues.patch:-p2 \
		${FILESDIR}/0006-xen-pvh-enable-mmu_update-hypercall.patch:-p2 \
		${FILESDIR}/0007-iommu-fix-usage-of-shared-EPT-IOMMU-page-tables-on-P.patch:-p2 \
		${FILESDIR}/0001-x86-pvh-use-a-custom-IO-bitmap-for-PVH-hardware-doma.patch:-p2 \
		${FILESDIR}/0002-x86-pvh-trap-access-to-sensitive-IO-ports.patch:-p2 \
		${FILESDIR}/xsa156-4.5.patch:-p2 \
		${FILESDIR}/xsa159.patch:-p2 \
		${FILESDIR}/xsa165-4.5.patch:-p2 \
		${FILESDIR}/xsa166-4.5.patch:-p2 \
		${FILESDIR}/xsa167-4.6.patch:-p2 \
		${FILESDIR}/xsa168.patch:-p2 \
		${FILESDIR}/xsa170-4.5.patch:-p2


.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		Only supported on FreeBSD
.endif

.if ${OSVERSION} < 1100055
IGNORE=		Only supported on recent FreeBSD 11
.endif

do-install:
	${MKDIR} ${STAGEDIR}/boot
	${INSTALL_PROGRAM} ${WRKSRC}/xen ${STAGEDIR}/boot
	${INSTALL_DATA} ${FILESDIR}/xen.4th ${STAGEDIR}/boot

.include <bsd.port.mk>

#Filter out LDFLAGS
.undef LDFLAGS
RUN_DEPENDS:=	${RUN_DEPENDS:N*gcc*}
