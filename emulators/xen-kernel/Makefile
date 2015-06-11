# $FreeBSD$

PORTNAME=	xen
PKGNAMESUFFIX=	-kernel
PORTVERSION=	4.5.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design

LICENSE=	GPLv2

ONLY_FOR_ARCH=	amd64

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
EXTRA_PATCHES=	${FILESDIR}/iommu_share_p2m_table.patch:-p2 \
		${FILESDIR}/0001-x86-pvh-disable-posted-interrupts.patch:-p2 \
		${FILESDIR}/xsa117.patch:-p2 \
		${FILESDIR}/xsa118-4.5-unstable-1.patch:-p2 \
		${FILESDIR}/xsa118-4.5-unstable-2.patch:-p2 \
		${FILESDIR}/xsa121.patch:-p2 \
		${FILESDIR}/xsa122.patch:-p2 \
		${FILESDIR}/xsa123.patch:-p2 \
		${FILESDIR}/xsa125.patch:-p2 \
		${FILESDIR}/xsa127-4.x.patch:-p2 \
		${FILESDIR}/xsa132.patch:-p2 \
		${FILESDIR}/xsa134.patch:-p2 \
		${FILESDIR}/xsa136.patch:-p2

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
