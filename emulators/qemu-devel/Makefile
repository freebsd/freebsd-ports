# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.9.1s.20080302
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://qemu.org/:release \
		http://qemu-forum.ipi.fi/qemu-snapshots/:snapshot \
		http://people.fruitsalad.org/nox/qemu/:snapshot \
		http://www.volny.cz/xnavara/qemu/:snapshot \
		http://people.brandeis.edu/~jcoiner/qemu_idedma/:idedma \
		http://people.freebsd.org/~maho/qemu/:misc
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-snapshot-2008-03-02_05
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot
DIST_SUBDIR=	qemu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	QEMU CPU Emulator - development snapshot

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GCC=	3.4
PATCH_STRIP=	-lp1
MAKE_ENV+=	BSD_MAKE="${MAKE}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=		qemu.1 qemu-img.1
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	qemu-[0-9]*

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
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl --disable-gfx-check
.else
USE_SDL=	sdl
.endif

.if defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=	--disable-vnc-tls
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
