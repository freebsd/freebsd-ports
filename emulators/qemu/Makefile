# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	0.11.1
PORTREVISION=	13
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://bellard.org/qemu/
MASTER_SITE_SUBDIR=	qemu
DIST_SUBDIR=	qemu

MAINTAINER=	nox@FreeBSD.org
COMMENT=	QEMU CPU Emulator

HAS_CONFIGURE=	yes
USE_GCC=	any
USES=		gmake perl5
USE_PERL5=	build
PATCH_STRIP=	-p1
MAKE_ENV+=	BSD_MAKE="${MAKE}"
MAN1=		qemu.1 qemu-img.1
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	qemu-devel-[0-9]*

OPTIONS_DEFINE=	KQEMU RTL8139_TIMER SAMBA SDL GNUTLS CURL PCAP GNS3 \
		CDROM_DMA ADD_AUDIO ALL_TARGETS
KQEMU_DESC=		Build with (alpha!) accelerator module
RTL8139_TIMER_DESC=	allow use of re(4) nic with FreeBSD guests
SAMBA_DESC=		samba dependency (for -smb)
SDL_DESC=		SDL/X dependency (graphical output)
GNUTLS_DESC=		gnutls dependency (vnc encryption)
CURL_DESC=		libcurl dependency (remote images)
PCAP_DESC=		pcap dependency (networking with bpf)
GNS3_DESC=		gns3 patches (udp, promiscuous multicast)
CDROM_DMA_DESC=		IDE CDROM DMA
ADD_AUDIO_DESC=		Emulate more audio hardware (experimental!)
ALL_TARGETS_DESC=	Also build non-x86 targets
OPTIONS_DEFAULT=	SDL GNUTLS CURL PCAP GNS3 CDROM_DMA ALL_TARGETS

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MALL_TARGETS)
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu
PLIST_SUB+=	ALLTARGETS="@comment "
.else
PLIST_SUB+=	ALLTARGETS=""
.endif

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}

.if empty(PORT_OPTIONS:MSDL)
CONFIGURE_ARGS+=	--disable-sdl
.else
USE_SDL=	sdl
.endif

.if empty(PORT_OPTIONS:MGNUTLS)
CONFIGURE_ARGS+=	--disable-vnc-tls
.else
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.endif

.if empty(PORT_OPTIONS:MCURL)
CONFIGURE_ARGS+=	--disable-curl
.else
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if ${PORT_OPTIONS:MPCAP}
CONFIGURE_ARGS+=	--enable-pcap
.endif

.if ${PORT_OPTIONS:MADD_AUDIO}
CONFIGURE_ARGS+=	--audio-card-list=ac97,es1370,sb16,cs4231a,adlib,gus
.endif

# XXX
CONFIGURE_ARGS+=	--disable-bsd-user

.if ${PORT_OPTIONS:MSAMBA}
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba36
.endif

.if ${PORT_OPTIONS:MKQEMU}
BUILD_DEPENDS+=	kqemu-kmod-devel>=1.4.0pre1:${PORTSDIR}/emulators/kqemu-kmod-devel
RUN_DEPENDS+=	kqemu-kmod-devel>=1.4.0pre1:${PORTSDIR}/emulators/kqemu-kmod-devel
.else
CONFIGURE_ARGS+=	--disable-kqemu
.endif

.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS=1
.else
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.endif

.if !defined(STRIP) || ${STRIP} == ""
CONFIGURE_ARGS+=--disable-strip
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
.if ${PORT_OPTIONS:MRTL8139_TIMER}
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/rtl8139-re-patch
.endif
.if ${PORT_OPTIONS:MPCAP}
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/pcap-patch
.endif
.if ${PORT_OPTIONS:MGNS3}
	@cd ${WRKSRC} && ${PATCH} -p1 --quiet < ${FILESDIR}/gns3-patch
.endif
.if empty(PORT_OPTIONS:MCDROM_DMA)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/cdrom-dma-patch
.endif
	@${REINPLACE_CMD} -E \
		-e "/^by Tibor .TS. S/s|Sch.*z.$$|Schuetz.|" \
		${WRKSRC}/qemu-doc.texi
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
