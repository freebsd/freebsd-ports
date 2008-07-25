# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.9.1
PORTREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	http://bellard.org/qemu/:release \
		http://qemu.org/:release \
		http://people.freebsd.org/~maho/qemu/:misc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release
DIST_SUBDIR=	qemu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	QEMU CPU Emulator

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GCC=	3.4
PATCH_STRIP=	-lp1
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}
MAKE_ENV+=	BSD_MAKE="${MAKE}" LDFLAGS="${LDFLAGS}"
MAN1=		qemu.1 qemu-img.1
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	qemu-devel-[0-9]*

OPTIONS=	KQEMU "Build with (alpha!) accelerator module" Off \
		RTL8139_TIMER "allow use of re(4) nic with FreeBSD guests" Off \
		SAMBA "samba dependency (for -smb)" Off \
		SDL "SDL/X dependency (graphical output)" On \
		GNUTLS "gnutls dependency (vnc encryption)" On \
		CDROM_DMA "IDE CDROM DMA" On

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
# 5.x base gcc segfaults in target-mips/op_mem.c
BUILD_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
CC=	gcc34
.endif

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl --disable-gfx-check
.else
USE_SDL=	sdl
.endif

.if defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=       --disable-vnc-tls
.else
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.endif

.if defined (WITH_HACKS_CIRRUS) || defined (WITH_HACKS)
DISTFILES+=	patch3_cirrus:misc
.endif

.if defined(WITH_SAMBA)
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba3
.endif

.if defined(WITH_KQEMU)
BUILD_DEPENDS+=	kqemu-kmod>=1.3.0pre5:${PORTSDIR}/emulators/kqemu-kmod
.else
CONFIGURE_ARGS+=	--disable-kqemu
.endif

.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS=${NOPORTDOCS}
.else
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.endif

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=x86_64
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/kqemu
	@${TOUCH} ${WRKSRC}/kqemu/Makefile
	@${ECHO} all: > ${WRKSRC}/kqemu/Makefile.freebsd

pre-patch:
	@for A in ${ONLY_FOR_ARCHS}; do \
		${MKDIR} ${WRKSRC}/bsd/$$A; \
	done

post-patch:
.if defined(WITH_RTL8139_TIMER)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/rtl8139-re-patch
.endif
.if defined(WITHOUT_CDROM_DMA)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/cdrom-dma-patch
.endif
	@${REINPLACE_CMD} -E \
		-e "s,^(CFLAGS=).*,\1${CFLAGS} -fno-strict-aliasing," \
		-e "s,^(LDFLAGS=).*,\1${LDFLAGS}," \
		${WRKSRC}/Makefile.target
	@${REINPLACE_CMD} -E \
		-e "s,^(CFLAGS=).*,\1${CFLAGS} -fno-strict-aliasing -I.," \
		-e "s,^(LDFLAGS=).*,\1${LDFLAGS}," \
		${WRKSRC}/Makefile

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${PREFIX}/etc
	@if [ ! -f ${PREFIX}/etc/qemu-ifup ]; then \
	    ${CP} -p ${PREFIX}/etc/qemu-ifup.sample ${PREFIX}/etc/qemu-ifup ; \
	fi
	@if [ ! -f ${PREFIX}/etc/qemu-ifdown ]; then \
	    ${CP} -p ${PREFIX}/etc/qemu-ifdown.sample ${PREFIX}/etc/qemu-ifdown ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
