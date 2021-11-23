PORTNAME=	xen
PORTVERSION=	4.15.0
PORTREVISION=	2
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
		lib/debug/boot/xen.debug

# Fix grant/foreign mapping cache attributes on Intel.
EXTRA_PATCHES+=	${PATCHDIR}/0001-x86-mtrr-remove-stale-function-prototype.patch:-p1 \
		${PATCHDIR}/0002-x86-mtrr-move-epte_get_entry_emt-to-p2m-ept.c.patch:-p1 \
		${PATCHDIR}/0003-x86-ept-force-WB-cache-attributes-for-grant-and-fore.patch:-p1

# Fix build with clang 13.0.0
EXTRA_PATCHES+=	${PATCHDIR}/0001-efi-fix-alignment-of-function-parameters-in-compat-m.patch:-p1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
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
