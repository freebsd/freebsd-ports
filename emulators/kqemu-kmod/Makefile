# New ports collection makefile for:	kqemu-kmod
# Date created:				2005/10/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kqemu
PORTVERSION=	1.3.0.p11
PORTREVISION=	12
CATEGORIES=	emulators kld
MASTER_SITES=	http://bellard.org/qemu/ \
		http://qemu.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nox
PKGNAMESUFFIX=	-kmod
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.p/pre/}
DIST_SUBDIR=	kqemu

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Kernel Accelerator for QEMU CPU Emulator

ONLY_FOR_ARCHS=	i386 amd64
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}
CONFLICTS=	kqemu-kmod-devel-[0-9]*

USE_RC_SUBR=	kqemu

.include <bsd.port.pre.mk>

PORTDOCS=	kqemu-doc.html kqemu-tech.html
PLIST_FILES=	"include/kqemu/kqemu.h"
PLIST_FILES+=	"@dirrm include/kqemu"
PLIST_FILES+=	"@cwd /"
PLIST_FILES+=	${KMODDIR:C,^/,,}/kqemu.ko
PLIST_FILES+=	"@unexec kldxref ${KMODDIR}"

MAKEFILE=	Makefile.freebsd

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=x86_64
.endif

# install where x11/nvidia-driver does also:
KMODDIR=	/boot/modules

MAKE_ENV+=	KMODDIR="${KMODDIR}"

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

.if ${OSVERSION} >= 700024 && ${OSVERSION} < 700053 && !defined(NOKSE)
# XXX this is wrong if you have `nooption KSE' in your kernel config,
# please define NOKSE in that case (no longer a problem after attilio's
# Sun Jul 22 21:35:44 2007 UTC commit removing the KSE ABI incompatiblity)
CFLAGS+=	-DKSE
.endif

CFLAGS+=       ${DEBUG_FLAGS}

post-extract:
.if ${OSVERSION} >= 700024 && ${OSVERSION} < 700053 && !defined(NOKSE)
	@${ECHO_MSG} "Compiling with -DKSE."
	@${ECHO_MSG} "If this is wrong (i.e. you have \`nooption KSE' in your kernel config),"
	@${ECHO_MSG} "then please define NOKSE."
.endif

# 7.1 and head have seperate gdts also on amd64 now so the tss fixup code
# is no longer needed there
post-patch:
.if ${OSVERSION} >= 701100 && (${OSVERSION} < 800000 || ${OSVERSION} >= 800046)
	@cd ${WRKSRC} && ${PATCH} -R --quiet < ${FILESDIR}/patch-tssworkaround
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} beforedepend && ${LN} -s @/sys sys)
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

.include <bsd.port.post.mk>
