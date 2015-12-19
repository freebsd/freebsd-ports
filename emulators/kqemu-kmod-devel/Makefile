# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	kqemu
DISTVERSION=	1.4.0pre1
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://bellard.org/qemu/ \
		http://qemu.org/ \
		LOCAL/nox
PKGNAMESUFFIX=	-kmod-devel
DIST_SUBDIR=	kqemu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kernel Accelerator for QEMU CPU Emulator (development version)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64
HAS_CONFIGURE=	yes
USE_GCC=	any
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}
CONFLICTS=	kqemu-kmod-[0-9]*

USE_RC_SUBR=	kqemu

USES=		kmod gmake uidfix

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

PORTDOCS=	kqemu-doc.html kqemu-tech.html
PLIST_FILES=	"include/kqemu/kqemu.h"
PLIST_FILES+=	${KMODDIR}/kqemu.ko

MAKEFILE=	Makefile.freebsd

MAKE_ARGS+=	LDFLAGS="${LDFLAGS:S/^-Wl,//}"

.if ${ARCH} == "amd64"
MAKE_CMD_ARGS+=	ARCH=x86_64
.endif

CFLAGS+=	${DEBUG_FLAGS}

post-patch:
# Apply extra patches from the qemu-devel list; in the unlikely case that
# these cause regressions please define WITHOUT_EXTRA_PATCHES and post
# details about your host _and_ guest on freebsd-emulation@freebsd.org
#  - Thanx!
.if !defined(WITHOUT_EXTRA_PATCHES)
	for i in ${FILESDIR}/extra-patch-*; do \
		${PATCH} -d ${WRKSRC} --quiet <$$i;\
	done
.endif
	@${REINPLACE_CMD} -e '/CC=/s,gcc,${CC},' ${WRKSRC}/common/Makefile

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} beforedepend && ${LN} -sfh machine/../../sys sys)
	@(cd ${BUILD_WRKSRC}/common; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${MAKE_CMD_ARGS} ${ALL_TARGET})
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} DESTDIR=${STAGEDIR} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kqemu
	${INSTALL_DATA} ${WRKSRC}/kqemu.h ${STAGEDIR}${PREFIX}/include/kqemu

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/kqemu-doc.html ${WRKSRC}/kqemu-tech.html \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
