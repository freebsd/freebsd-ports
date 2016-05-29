# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	qemu
DISTVERSION=	2.6.0
CATEGORIES=	emulators
MASTER_SITES=	http://wiki.qemu.org/download/
PKGNAMESUFFIX=	-devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU CPU Emulator - development version

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
USES=		cpe gmake pkgconfig bison perl5 python:2,build tar:bzip2
USE_PERL5=	build
USE_XORG=	pixman x11 xext
USE_GNOME+=	cairo gdkpixbuf2 glib20
MAKE_ENV+=	BSD_MAKE="${MAKE}"
ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 # XXX someone wants to debug sparc64 hosts?

OPTIONS_DEFINE=	SAMBA X11 GTK2 OPENGL GNUTLS SASL JPEG PNG CURL \
		CDROM_DMA PCAP USBREDIR GNS3 X86_TARGETS \
		STATIC_LINK DOCS
SAMBA_DESC=		samba dependency (for -smb)
GNUTLS_DESC=		gnutls dependency (vnc encryption)
SASL_DESC=		cyrus-sasl dependency (vnc encryption)
JPEG_DESC=		jpeg dependency (vnc lossy compression)
PNG_DESC=		png dependency (vnc compression)
CDROM_DMA_DESC=		IDE CDROM DMA
PCAP_DESC=		pcap dependency (networking with bpf)
USBREDIR_DESC=		usb device network redirection (experimental!)
GNS3_DESC=		gns3 patches (promiscuous multicast)
X86_TARGETS_DESC=	Build only x86 system targets
STATIC_LINK_DESC=	Statically link the executables
OPTIONS_DEFAULT=X11 GTK2 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL PCAP GNS3
OPTIONS_SUB=	yes
X11_USE=	SDL=sdl
X11_CONFIGURE_ON=	--enable-sdl
X11_CONFIGURE_OFF=	--disable-sdl
GTK2_USE=	GNOME=gtk20,vte
GTK2_USES=	gettext
GTK2_CONFIGURE_OFF=	--disable-gtk --disable-vte
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=	--disable-gnutls
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_OFF=	--disable-vnc-sasl
JPEG_USES=		jpeg
JPEG_CONFIGURE_OFF=	--disable-vnc-jpeg
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_OFF=	--disable-vnc-png
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--disable-curl
OPENGL_USE=	GL=yes
OPENGL_CONFIGURE_OFF=	--disable-opengl
USBREDIR_BUILD_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_RUN_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_CONFIGURE_OFF=	--disable-usb-redir
PCAP_CONFIGURE_ON=	--enable-pcap
PCAP_EXTRA_PATCHES=	${FILESDIR}/pcap-patch ${FILESDIR}/pcap-patch-net_net.c
STATIC_LINK_CONFIGURE_ON=	--static
STATIC_LINK_PREVENTS=		GTK2 X11
STATIC_LINK_PREVENTS_MSG=	X11 ui cannot be built static
SAMBA_RUN_DEPENDS=	${LOCALBASE}/sbin/smbd:net/samba36
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html
DOCS_USES=		makeinfo
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=1

PORTDOCS=	docs qemu-doc.html qemu-tech.html qmp-commands.txt

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS+=--localstatedir=/var --extra-ldflags=-L\"${LOCALBASE}/lib\" \
		--disable-libssh2 --enable-debug \
		--prefix=${PREFIX} --cc=${CC} --enable-docs --disable-kvm \
		--disable-linux-user --disable-linux-aio --disable-xen \
		--smbd=${LOCALBASE}/sbin/smbd --enable-debug-info --python=${PYTHON_CMD} \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"

LIB_DEPENDS+=	libnettle.so:security/nettle \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

.include <bsd.port.options.mk>

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

# -lprocstat actually only _needs_ -lelf after r249666 or r250870 (MFC)
# but it shouldn't matter much
post-patch:
	@${REINPLACE_CMD} -e '/LIBS/s|-lprocstat|-lprocstat -lelf|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/libs_qga=/s|glib_libs|glib_libs -lintl|' ${WRKSRC}/configure
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

post-patch-CDROM_DMA-off:
	@${REINPLACE_CMD} -e '/USE_DMA_CDROM/d' ${WRKSRC}/hw/ide/internal.h

post-patch-GNS3-on:
	@${REINPLACE_CMD} -e 's|(buf\[0\] & 1) && (rctl & E1000_RCTL_MPE)|buf[0] \& 1|' \
		${WRKSRC}/hw/net/e1000.c

# XXX need to disable usb host code on head while it's not ported to the
# new usb stack yet
post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|^(HOST_USB=)bsd|\1stub|" \
		${WRKSRC}/config-host.mak

.if !target(post-install)
post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ivshmem-*

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif

.include <bsd.port.mk>
