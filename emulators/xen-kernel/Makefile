# $FreeBSD$

PORTNAME=	xen
PORTVERSION=	4.7.2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.xenproject.org/release/xen/${PORTVERSION}/
PKGNAMESUFFIX=	-kernel

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

USES=		cpe gmake python:build

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
		${FILESDIR}/xsa215.patch:-p1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

.if ${OSVERSION} < 1100055
IGNORE=		only supported on recent FreeBSD 11
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
