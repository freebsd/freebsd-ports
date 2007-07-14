# New ports collection makefile for:	kqemu-kmod
# Date created:				2005/10/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kqemu
PORTVERSION=	1.3.0.p11
PORTREVISION=	1
CATEGORIES=	emulators kld
MASTER_SITES=	http://fabrice.bellard.free.fr/qemu/ \
		http://qemu.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nox
PKGNAMESUFFIX=	-kmod
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.p/pre/}
DIST_SUBDIR=	kqemu

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Kernel Accelerator for QEMU CPU Emulator (development version)

ONLY_FOR_ARCHS=	i386 amd64
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}

USE_RC_SUBR=	kqemu

.include <bsd.port.pre.mk>

PORTDOCS=	kqemu-doc.html kqemu-tech.html
PLIST_FILES=	"include/kqemu/kqemu.h"
PLIST_FILES+=	"@dirrm include/kqemu"
PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/kqemu.ko
.if ${OSVERSION} >= 500000
PLIST_FILES+=	"@unexec kldxref ${KMODDIR}"
.endif

MAKEFILE=	Makefile.freebsd

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=x86_64
.endif

# install where x11/nvidia-driver does also:
.if ${OSVERSION} >= 500000
KMODDIR=	/boot/modules
.endif

MAKE_ENV+=	KMODDIR="${KMODDIR}"

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		kqemu requires kernel source to be installed
.endif

.if ${OSVERSION} >= 700024 && !defined(NOKSE)
# XXX this is wrong if you have `nooption KSE' in your kernel config,
# please define NOKSE in that case
CFLAGS+=	-DKSE
.endif

# XXX the following is wrong if you run a custom SMP kernel on a
# singleprocessor machine (but it probably doesn't really matter)
KERNCONF!=	${UNAME} -v | ${SED} 's-.*/--'
NCPU!=		${SYSCTL} -n hw.ncpu 2>/dev/null
# we know 7.x GENERIC has SMP
.if ${KERNCONF} == "GENERIC" && ${OSVERSION} >= 700000
CFLAGS+=	-DSMP
.elif ${NCPU} > 1
CFLAGS+=	-DSMP
.endif

post-extract:
.if ${OSVERSION} >= 700024 && !defined(NOKSE)
	@${ECHO_MSG} "Compiling with -DKSE."
	@${ECHO_MSG} "If this is wrong (i.e. you have \`nooption KSE' in your kernel config),"
	@${ECHO_MSG} "then please define NOKSE."
.endif

do-build:
	@(cd ${BUILD_WRKSRC}/common; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${MKDIR} ${PREFIX}/include/kqemu
	${INSTALL_DATA} ${WRKSRC}/kqemu.h ${PREFIX}/include/kqemu
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/kqemu-doc.html ${WRKSRC}/kqemu-tech.html \
		${DOCSDIR}
.endif
.if ${OSVERSION} < 500000
	if [ ! -e /dev/kqemu ]; then\
		mknod /dev/kqemu c 250 0 ; \
	fi
	${CHMOD} 666 /dev/kqemu
.endif

.include <bsd.port.post.mk>
