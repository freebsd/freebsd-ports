# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.9.1s.20080620
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	http://bellard.org/qemu/:release \
		http://qemu-forum.ipi.fi/qemu-snapshots/:snapshot \
		${MASTER_SITE_LOCAL}:snapshot
MASTER_SITE_SUBDIR=	nox/:snapshot
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-snapshot-2008-06-20_19
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot
DIST_SUBDIR=	qemu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	QEMU CPU Emulator - development snapshot

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
PATCH_STRIP=	-lp1
MAKE_ENV+=	BSD_MAKE="${MAKE}" LDFLAGS="${LDFLAGS}"
MAN1=		qemu.1 qemu-img.1
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	qemu-[0-9]*
MAKE_JOBS_SAFE=	yes

OPTIONS=	KQEMU "Build with (alpha!) accelerator module" Off \
		RTL8139_TIMER "allow use of re(4) nic with FreeBSD guests" Off \
		SAMBA "samba dependency (for -smb)" Off \
		SDL "SDL/X dependency (graphical output)" On \
		GNUTLS "gnutls dependency (vnc encryption)" On \
		PCAP "pcap dependency (networking with bpf)" On \
		CDROM_DMA "IDE CDROM DMA" On \
		ALL_TARGETS "Also build dyngen targets (requires gcc34)" On

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ALL_TARGETS)
CONFIGURE_ARGS+=	--disable-gcc-check --target-list=i386-softmmu,sparc-softmmu,x86_64-softmmu,mips-softmmu,mipsel-softmmu,mips64-softmmu,mips64el-softmmu,arm-softmmu,m68k-softmmu,cris-softmmu
PLIST_SUB+=    DYNGEN="@comment "
.else
USE_GCC=	3.4
PLIST_SUB+=    DYNGEN=""
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

.if defined(WITH_PCAP)
CONFIGURE_ARGS+=	--enable-pcap
.endif

.if defined(WITH_SAMBA)
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba3
.endif

.if defined(WITH_KQEMU)
BUILD_DEPENDS+=	kqemu-kmod-devel>=1.4.0pre1:${PORTSDIR}/emulators/kqemu-kmod-devel
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
.if defined(WITH_PCAP)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/pcap-patch
.endif
.if defined(WITHOUT_CDROM_DMA)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/cdrom-dma-patch
.endif
	@${REINPLACE_CMD} -E \
		-e "s|^(CFLAGS=).*|\1${CFLAGS} -fno-strict-aliasing|" \
		-e "s|^(LDFLAGS=).*|\1${LDFLAGS}|" \
		${WRKSRC}/Makefile.target
	@${REINPLACE_CMD} -E \
		-e "s|^(CFLAGS=).*|\1${CFLAGS} -fno-strict-aliasing -I.|" \
		-e "s|^(LDFLAGS=).*|\1${LDFLAGS}|" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		-e "1s|^(#! )/usr/bin/perl|\1${PERL}|" \
		${WRKSRC}/texi2pod.pl

.if ${OSVERSION} >= 800091
# XXX need to disable usb host code on head while it's not ported to the
# new usb stack yet
post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|^(HOST_USB=)bsd|\1stub|" \
		${WRKSRC}/config-host.mak
.endif

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
