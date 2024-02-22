PORTNAME=	xen
PKGNAMESUFFIX=	-kernel
DISTVERSION=	4.18.0.20240201
CATEGORIES=	emulators

USE_GITLAB=	yes
GL_ACCOUNT=	xen-project
GL_TAGNAME=	b1fdd7d0e47e0831ac7a99d0417385fc10d3068c

MAINTAINER=	royger@FreeBSD.org
COMMENT=	Hypervisor using a microkernel design
WWW=		https://www.xenproject.org/

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

# Workaround clang code generation bug.
EXTRA_PATCHES+=        ${PATCHDIR}/v2-0001-x86-altcall-use-an-union-as-register-type-for-fun.patch:-p1

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
