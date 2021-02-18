# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	4.1.1
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
PKGNAMESUFFIX=	41
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER?=	bofh@FreeBSD.org
COMMENT?=	QEMU CPU Emulator - 4.1.X branch

LICENSE=	GPLv2

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
LIB_DEPENDS?=	libnettle.so:security/nettle \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libepoxy.so:graphics/libepoxy \
		libpcre2-8.so:devel/pcre2

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le
USES=		bison compiler:c11 cpe gmake gnome iconv:wchar_t perl5 \
		pkgconfig python:build tar:xz xorg
USE_XORG=	pixman
USE_GNOME=	cairo glib20 libxml2

USE_PERL5=	build

PORTSCOUT=	limit:^4\.1\.

HAS_CONFIGURE=	yes
MAKE_ENV+=	BSD_MAKE="${MAKE}" V=1

OPTIONS_DEFINE=	SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL \
		VDE CDROM_DMA PCAP USBREDIR X86_TARGETS \
		STATIC_LINK DOCS ISCSI
OPTIONS_SINGLE=	NCURSES
OPTIONS_SINGLE_NCURSES=	NCURSES_DEFAULT NCURSES_BASE NCURSES_PORT
CDROM_DMA_DESC=		IDE CDROM DMA
GNUTLS_DESC=		gnutls dependency (vnc encryption)
ISCSI_DESC=		libiscsi dependency (iSCSI client for emulated drives)
JPEG_DESC=		jpeg dependency (vnc lossy compression)
NCURSES_DEFAULT_DESC=	Depend on ncurses (ports if installed, otherwise base)
NCURSES_BASE_DESC=	Depend on ncurses in base
NCURSES_PORT_DESC=	Depend on devel/ncurses in ports
PCAP_DESC=		pcap dependency (networking with bpf)
PNG_DESC=		png dependency (vnc compression)
SAMBA_DESC=		samba dependency (for -smb)
SASL_DESC=		cyrus-sasl dependency (vnc encryption)
STATIC_LINK_DESC=	Statically link the executables
USBREDIR_DESC=		usb device network redirection (experimental!)
VDE_DESC=		vde dependency (for vde networking)
X86_TARGETS_DESC=	Build only x86 system targets
OPTIONS_DEFAULT=X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL PCAP NCURSES_DEFAULT VDE
OPTIONS_SUB=	yes
CURL_CONFIGURE_OFF=	--disable-curl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=1
DOCS_USES=		makeinfo
GNUTLS_CONFIGURE_OFF=	--disable-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GTK3_CONFIGURE_OFF=	--disable-gtk --disable-vte
GTK3_LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
GTK3_USE=	GNOME=gdkpixbuf2,gtk30,vte3 XORG=x11,xext
GTK3_USES=	gettext gl
ISCSI_LIB_DEPENDS=	libiscsi.so:net/libiscsi
ISCSI_CONFIGURE_OFF=	--disable-libiscsi
JPEG_CONFIGURE_OFF=	--disable-vnc-jpeg
JPEG_USES=		jpeg
NCURSES_DEFAULT_USES=	ncurses
NCURSES_BASE_USES=	ncurses:base
NCURSES_PORT_USES=	ncurses:port
OPENGL_CONFIGURE_OFF=	--disable-opengl
OPENGL_USE=	GL=gl
OPENGL_USES=	gl
PCAP_CONFIGURE_ON=	--enable-pcap
PCAP_EXTRA_PATCHES=	${FILESDIR}/pcap-patch-qapi_net.json ${FILESDIR}/pcap-patch-net_net.c \
			${FILESDIR}/pcap-patch-net_clients.h
PNG_CONFIGURE_OFF=	--disable-vnc-png
PNG_LIB_DEPENDS=	libpng.so:graphics/png
SAMBA_CONFIGURE_ON=	--smbd=${LOCALBASE}/sbin/smbd
SAMBA_USES=		samba:run # smbd
SASL_CONFIGURE_OFF=	--disable-vnc-sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
STATIC_LINK_CONFIGURE_ON=	--static
STATIC_LINK_PREVENTS=		GTK3 X11
STATIC_LINK_PREVENTS_MSG=	X11 ui cannot be built static
USBREDIR_BUILD_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_CONFIGURE_OFF=	--disable-usb-redir
USBREDIR_RUN_DEPENDS=	usbredir>=0.6:net/usbredir
VDE_CONFIGURE_OFF=	--disable-vde
VDE_LIB_DEPENDS=	libvdeplug.so:net/vde2
X11_CONFIGURE_ENABLE=	sdl
X11_USE=	SDL=sdl2 XORG=x11,xext GNOME=gdkpixbuf2
X11_USES=	sdl
X86_TARGETS_USE_OFF=	XORG=pixman,x11
X86_TARGETS_USES_OFF=	xorg
INSTALLS_ICONS=		yes

PORTDOCS?=	docs interop/.buildinfo interop/* qemu-doc.html qemu-doc.txt qemu-ga-ref.html qemu-ga-ref.txt \
	       	qemu-qmp-ref.html qemu-qmp-ref.txt specs/.buildinfo specs/*

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS?=	--localstatedir=/var --extra-ldflags=-L\"/usr/lib\" \
		--extra-ldflags=-L\"${LOCALBASE}/lib\" --disable-libssh --enable-debug \
		--prefix=${PREFIX} --cc=${CC} --enable-netmap --enable-docs --disable-kvm \
		--disable-linux-user --disable-linux-aio --disable-xen \
		--enable-debug-info --python=${PYTHON_CMD} \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"

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

PLIST_SUB+=	LINUXBOOT_DMA=""

post-patch-CDROM_DMA-off:
	@${REINPLACE_CMD} -e '/USE_DMA_CDROM/d' ${WRKSRC}/include/hw/ide/internal.h

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

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif

.include <bsd.port.mk>
