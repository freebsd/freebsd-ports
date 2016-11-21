# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	2.7.90.g20161116
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	GH \
		LOCAL/nox:dtc \
		http://people.freebsd.org/~nox/tmp/distfiles/:dtc
PKGNAMESUFFIX?=	-sbruno
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		dtc-v1.4.0${EXTRACT_SUFX}:dtc
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	sbruno@FreeBSD.org
COMMENT?=	QEMU CPU Emulator - github bsd-user branch

BROKEN_FreeBSD_9=	does not build

LICENSE=	GPLv2
USE_GITHUB=	yes
GH_ACCOUNT=	seanbruno
GH_PROJECT=	${PORTNAME}-bsd-user
GH_TAGNAME=	ff68442
HAS_CONFIGURE=	yes
USES=		gmake pkgconfig bison perl5 python:2,build
USE_PERL5=	build
PATCH_STRIP=	-p1
MAKE_ENV+=	BSD_MAKE="${MAKE}" V=1
ONLY_FOR_ARCHS=	amd64 powerpc powerpc64 # XXX someone wants to debug sparc64 hosts?
BROKEN_i386=	aarch64 system target is currently broken for i386 hosts, disable for now while dealing with upstream

OPTIONS_DEFINE=	SAMBA X11 GTK2 OPENGL GNUTLS SASL JPEG PNG CURL \
		CDROM_DMA PCAP USBREDIR X86_TARGETS BSD_USER \
		STATIC_LINK DOCS
SAMBA_DESC=		samba dependency (for -smb)
GNUTLS_DESC=		gnutls dependency (vnc encryption)
SASL_DESC=		cyrus-sasl dependency (vnc encryption)
JPEG_DESC=		jpeg dependency (vnc lossy compression)
PNG_DESC=		png dependency (vnc compression)
CDROM_DMA_DESC=		IDE CDROM DMA
PCAP_DESC=		pcap dependency (networking with bpf)
USBREDIR_DESC=		usb device network redirection (experimental!)
X86_TARGETS_DESC=	Don't build non-x86 system targets
BSD_USER_DESC=		Also build bsd-user targets (for testing)
STATIC_LINK_DESC=	Statically link the executables
OPTIONS_DEFAULT=X11 GTK2 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL PCAP

.if !defined(QEMU_USER_STATIC)
CONFLICTS_INSTALL=	qemu-[0-9]* qemu-devel-*
.endif

.if defined(QEMU_USER_STATIC)
.if exists(/usr/sbin/binmiscctl)
USE_RC_SUBR=	qemu_user_static
SUB_LIST=	NAME=qemu_user_static
CONFIGURE_ARGS+=	--disable-tools
.endif
.else
# qemu-system-* targets require pixman to build, add an explicit dependency.
USE_XORG=	pixman
.endif

# When static linking we have a build dependency on libglib-2.0.a, otherwise
# we use glib20 in the usual way (shared-lib runtime dependency).
.if defined(QEMU_USER_STATIC)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libglib-2.0.a:devel/glib20
.else
USE_GNOME+=	glib20
.endif

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--extra-ldflags=-L\"${LOCALBASE}/lib\"
CONFIGURE_ARGS+=	--disable-libssh2
PORTDOCS=	docs qemu-doc.html qmp-commands.txt

.if defined(QEMU_USER_STATIC)
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=	--target-list=i386-bsd-user,sparc-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user,ppc-bsd-user
.else
CONFIGURE_ARGS+=	--target-list=i386-bsd-user,x86_64-bsd-user,sparc-bsd-user,sparc64-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user,mips64-bsd-user,mips64el-bsd-user,ppc-bsd-user,ppc64-bsd-user,aarch64-bsd-user
.endif
.else
.if ${PORT_OPTIONS:MX86_TARGETS}
.if ${PORT_OPTIONS:MBSD_USER}
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu,i386-bsd-user,sparc-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user,ppc-bsd-user
.else
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu,i386-bsd-user,x86_64-bsd-user,sparc-bsd-user,sparc64-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user,mips64-bsd-user,mips64el-bsd-user,ppc-bsd-user,ppc64-bsd-user,aarch64-bsd-user
.endif
.else
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu
.endif
.else
.if empty(PORT_OPTIONS:MBSD_USER)
CONFIGURE_ARGS+=	--disable-bsd-user
.else
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu,aarch64-softmmu,alpha-softmmu,arm-softmmu,cris-softmmu,lm32-softmmu,m68k-softmmu,microblaze-softmmu,microblazeel-softmmu,mips-softmmu,mipsel-softmmu,mips64-softmmu,mips64el-softmmu,or32-softmmu,ppc-softmmu,ppcemb-softmmu,ppc64-softmmu,sh4-softmmu,sh4eb-softmmu,sparc-softmmu,sparc64-softmmu,s390x-softmmu,xtensa-softmmu,xtensaeb-softmmu,unicore32-softmmu,moxie-softmmu,i386-bsd-user,sparc-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user,ppc-bsd-user
.endif
.endif
.endif
.endif

.if empty(PORT_OPTIONS:MBSD_USER)
PLIST_SUB+=	BSD_USER="@comment "
.else
PLIST_SUB+=	BSD_USER=""
.if ${ARCH} == "sparc64"
IGNORE=		bsd-user targets not tested on sparc64
.endif
.endif
.if empty(PORT_OPTIONS:MBSD_USER) || ${ARCH} != "amd64"
PLIST_SUB+=	BSD_USER64="@comment "
.else
PLIST_SUB+=	BSD_USER64=""
.endif

.if ${PORT_OPTIONS:MX86_TARGETS}
PLIST_SUB+=	NONX86="@comment "
.else
PLIST_SUB+=	NONX86=""
.endif

.if defined(QEMU_USER_STATIC)
PLIST_SUB+=	SOFTMMU="@comment "
PLIST_SUB+=	STATIC="-static"
.else
PLIST_SUB+=	SOFTMMU=""
PLIST_SUB+=	STATIC=""
.endif

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC} --enable-docs \
	--disable-linux-user --disable-linux-aio \
	--disable-kvm --disable-xen \
	--smbd=${LOCALBASE}/sbin/smbd \
	--enable-debug \
	--enable-debug-info \
	--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"

.if empty(PORT_OPTIONS:MX11)
CONFIGURE_ARGS+=	--disable-sdl
.else
CONFIGURE_ARGS+=	--enable-sdl
USE_SDL=	sdl
.endif

.if empty(PORT_OPTIONS:MGTK2)
CONFIGURE_ARGS+=	--disable-gtk --disable-vte
PLIST_SUB+=	GTK2="@comment "
.else
USE_GNOME+=	gtk20 vte
USES+=		gettext
PLIST_SUB+=	GTK2=""
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:security/gnutls
.endif

.if empty(PORT_OPTIONS:MSASL)
CONFIGURE_ARGS+=	--disable-vnc-sasl
.else
LIB_DEPENDS+=	libsasl2.so:security/cyrus-sasl2
.endif

.if empty(PORT_OPTIONS:MJPEG)
CONFIGURE_ARGS+=	--disable-vnc-jpeg
.else
USES+=		jpeg
.endif

.if empty(PORT_OPTIONS:MPNG)
CONFIGURE_ARGS+=	--disable-vnc-png
.else
LIB_DEPENDS+=	libpng.so:graphics/png
.endif

.if empty(PORT_OPTIONS:MCURL)
CONFIGURE_ARGS+=	--disable-curl
.else
LIB_DEPENDS+=	libcurl.so:ftp/curl
.endif

.if empty(PORT_OPTIONS:MOPENGL)
CONFIGURE_ARGS+=	--disable-opengl
.else
USE_GL=		yes
.endif

.if empty(PORT_OPTIONS:MUSBREDIR)
CONFIGURE_ARGS+=	--disable-usb-redir
.else
BUILD_DEPENDS+=	usbredir>=0.6:net/usbredir
RUN_DEPENDS+=	usbredir>=0.6:net/usbredir
.endif

.if ${PORT_OPTIONS:MPCAP}
CONFIGURE_ARGS+=	--enable-pcap
.else
CONFIGURE_ARGS+=	--disable-pcap
.endif

.if ${PORT_OPTIONS:MSTATIC_LINK}
.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MX11}
IGNORE=		the X11 ui cannot be built static
.endif
CONFIGURE_ARGS+=	--static
.endif

.if ${PORT_OPTIONS:MSAMBA}
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:net/samba36
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	texi2html:textproc/texi2html
USES+=		makeinfo
.else
MAKE_ARGS+=	NOPORTDOCS=1
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

.if ${ARCH} == "powerpc64"
MAKE_ARGS+=	ARCH=ppc64
.endif

.if ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--sparc_cpu=v9
.endif

CONFIGURE_ARGS+=	--python=${PYTHON_CMD}

# clang in freebsd 10 is unable to assemble linuxboot_dma.bin
.if (${OSVERSION} < 1100000)
PLIST_SUB+=	LINUXBOOT_DMA="@comment "
.else
PLIST_SUB+=	LINUXBOOT_DMA=""
.endif

post-patch:
	@${MV} ${WRKDIR}/dtc ${WRKSRC}
	@${REINPLACE_CMD} -e '/libs_qga=/s|glib_libs|glib_libs -lintl|' ${WRKSRC}/configure
# clang in freebsd 10 is unable to assemble linuxboot_dma.bin
.if (${OSVERSION} < 1100000)
	@${REINPLACE_CMD} -E \
		-e 's|linuxboot_dma.bin||' \
		${WRKSRC}/pc-bios/optionrom/Makefile
	@${REINPLACE_CMD} -E \
		-e 's|linuxboot_dma.bin||' \
		${WRKSRC}/Makefile
.endif

#.if ${PORT_OPTIONS:MPCAP}
#	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/pcap-patch
#.endif
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
		${WRKSRC}/scripts/texi2pod.pl

# XXX need to disable usb host code on head while it's not ported to the
# new usb stack yet
post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|^(HOST_USB=)bsd|\1stub|" \
		${WRKSRC}/config-host.mak

.if !target(post-install)
post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ivshmem-*
.endif

.include <bsd.port.mk>
