# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.15.1
CATEGORIES=	emulators
MASTER_SITES=	SAVANNAH:release \
		http://wiki.qemu.org/download/:release \
		LOCAL:snapshot
MASTER_SITE_SUBDIR=	qemu/:release nox/:snapshot
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release \
		sgabios-read-only-r8${EXTRACT_SUFX}:snapshot
DIST_SUBDIR=	qemu/${PORTVERSION}

PATCH_SITES=	http://code.gns3.net/qemu-patches/raw-file/0b69b9be6a8e/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nox@FreeBSD.org
COMMENT=	QEMU CPU Emulator - development version

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
PATCH_STRIP=	-p1
MAKE_ENV+=	BSD_MAKE="${MAKE}"
MAN1=		qemu.1 qemu-img.1
MAN8=		qemu-nbd.8
ONLY_FOR_ARCHS=	amd64 i386 powerpc # XXX someone wants to debug sparc64 hosts?
CONFLICTS_INSTALL=	qemu-[0-9]*
MAKE_JOBS_SAFE=	yes

OPTIONS=	SAMBA "samba dependency (for -smb)" Off \
		SDL "SDL/X dependency (graphical output)" On \
		OPENGL "OpenGL dependency" On \
		GNUTLS "gnutls dependency (vnc encryption)" On \
		SASL "cyrus-sasl dependency (vnc encryption)" On \
		JPEG "jpeg dependency (vnc lossy compression)" On \
		PNG "png dependency (vnc compression)" On \
		GA "glib20 dependency (guest agent)" On \
		CURL "libcurl dependency (remote images)" On \
		CDROM_DMA "IDE CDROM DMA" On \
		PCAP "pcap dependency (networking with bpf)" On \
		SEABIOS_GIT "add seabios snapshot (-bios seabios-devel.bin)" On \
		USBREDIR "usb device network redirection (experimental!)" Off \
		GNS3 "gns3 patches (udp, promiscuous multicast)" Off \
		ADD_AUDIO "Emulate more audio hardware (experimental!)" Off \
		ALL_TARGETS "Also build bsd-user targets (for testing)" Off

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--extra-ldflags=-L${LOCALBASE}/lib
PORTDOCS=	docs qemu-doc.html qemu-tech.html

.if defined(WITHOUT_ALL_TARGETS)
CONFIGURE_ARGS+=	--disable-bsd-user
PLIST_SUB+=	ALLTARGETS="@comment "
.else
PLIST_SUB+=	ALLTARGETS=""
.if ${ARCH} == "sparc64"
IGNORE=		bsd-user targets not tested on sparc64
.endif
.endif

.if defined(WITH_GNS3)
PATCHFILES+=	hw_e1000_c.patch
#PATCHFILES+=	net_c.patch
#PATCHFILES+=	net_h.patch
EXTRA_PATCHES+=	${FILESDIR}/net_c.patch
EXTRA_PATCHES+=	${FILESDIR}/net_h.patch
PATCHFILES+=	net_udp_c.patch
PATCHFILES+=	net_udp_h.patch
PATCHFILES+=	Makefile_objs.patch
EXTRA_PATCHES+=	${FILESDIR}/gns3-qemu-options.hx.patch
.endif

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC} --enable-docs \
	--disable-linux-user --disable-linux-aio \
	--disable-darwin-user --disable-kvm --disable-xen \
	--smbd=${LOCALBASE}/sbin/smbd \
	--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"${PREFIX}\\\"

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl
.else
USE_SDL=	sdl
.endif

.if defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=	--disable-vnc-tls
.else
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.endif

.if defined(WITHOUT_SASL)
CONFIGURE_ARGS+=	--disable-vnc-sasl
.else
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
.endif

.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--disable-vnc-jpeg
.else
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--disable-vnc-png
.else
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
.endif

.if defined(WITHOUT_GA)
CONFIGURE_ARGS+=	--disable-guest-agent --python="${NONEXISTENT}"
PLIST_SUB+=	GA="@comment "
.else
USE_PYTHON_BUILD=	yes
USE_GNOME+=	glib20
PLIST_SUB+=	GA=""
.endif

.if defined(WITHOUT_CURL)
CONFIGURE_ARGS+=	--disable-curl
.else
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=	--disable-opengl
.else
USE_GL=		yes
.endif

.if defined(WITHOUT_USBREDIR)
CONFIGURE_ARGS+=	--disable-usb-redir
.else
LIB_DEPENDS+=	usbredirparser:${PORTSDIR}/net/usbredir
.endif

.if defined(WITH_PCAP)
CONFIGURE_ARGS+=	--enable-pcap
.endif

.if defined(WITH_ADD_AUDIO)
CONFIGURE_ARGS+=	--audio-card-list=ac97,es1370,sb16,cs4231a,adlib,gus,hda
.endif

.if defined(WITH_SAMBA)
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba35
.endif

.if defined(WITH_SEABIOS_GIT)
RUN_DEPENDS+=	${LOCALBASE}/share/qemu/seabios-devel.bin:${PORTSDIR}/emulators/seabios-devel
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

.if ${ARCH} == "powerpc"
MAKE_ARGS+=	ARCH=ppc
.endif

.if ${ARCH} == "sparc64"
CONFIGURE_ARGS+= --sparc_cpu=v9
.endif

.if ${OSVERSION} < 900033 && ${ARCH} == "amd64"
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

post-patch:
.if defined(WITH_PCAP)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/pcap-patch
	@${REINPLACE_CMD} -f ${FILESDIR}/pcap-client-type.sed ${WRKSRC}/net.h
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
		${WRKSRC}/scripts/texi2pod.pl

.if ${OSVERSION} >= 800091
# XXX need to disable usb host code on head while it's not ported to the
# new usb stack yet
post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|^(HOST_USB=)bsd|\1stub|" \
		${WRKSRC}/config-host.mak
.endif

post-build:
	@${MAKE_ENV} ${GMAKE} -C${WRKDIR}/sgabios-read-only

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${DOCSDIR}/)
.endif
	@${INSTALL_DATA} ${WRKDIR}/sgabios-read-only/sgabios.bin ${DATADIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${PREFIX}/etc
	@if [ ! -f ${PREFIX}/etc/qemu-ifup ]; then \
	    ${CP} -p ${PREFIX}/etc/qemu-ifup.sample ${PREFIX}/etc/qemu-ifup ; \
	fi
	@if [ ! -f ${PREFIX}/etc/qemu-ifdown ]; then \
	    ${CP} -p ${PREFIX}/etc/qemu-ifdown.sample ${PREFIX}/etc/qemu-ifdown ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
