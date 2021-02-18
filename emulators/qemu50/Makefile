# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	5.0.0
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
PKGNAMESUFFIX=	50
DIST_SUBDIR=	qemu/${PORTVERSION}

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU CPU Emulator - 5.0.X branch

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libnettle.so:security/nettle \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libepoxy.so:graphics/libepoxy \
		libpcre2-8.so:devel/pcre2

USES=		bison compiler:c11 cpe gmake gnome iconv:wchar_t perl5 \
		pkgconfig python:build tar:xz xorg
USE_GNOME=	cairo glib20 libxml2
USE_PERL5=	build
USE_XORG=	pixman

PATCHFILES+=	55765822804f.patch:-p1
PATCHFILES+=	aa4d30f6618d.patch:-p1

#BROKEN_powerpc64=	fails to compile: In function aio_bh_poll: internal compiler error: Segmentation fault

#.if !defined(PKGNAMESUFFIX) || (${PKGNAMESUFFIX} != "-utils" && ${PKGNAMESUFFIX} != "-guest-agent")
#.endif

HAS_CONFIGURE=	yes
MAKE_ENV+=	BSD_MAKE="${MAKE}" V=1

OPTIONS_DEFINE=	SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL \
		VDE CDROM_DMA PCAP USBREDIR X86_TARGETS \
		STATIC_LINK DOCS NCURSES
SAMBA_DESC=		samba dependency (for -smb)
GNUTLS_DESC=		gnutls dependency (vnc encryption)
SASL_DESC=		cyrus-sasl dependency (vnc encryption)
JPEG_DESC=		jpeg dependency (vnc lossy compression)
PNG_DESC=		png dependency (vnc compression)
CDROM_DMA_DESC=		IDE CDROM DMA
PCAP_DESC=		pcap dependency (networking with bpf)
USBREDIR_DESC=		usb device network redirection (experimental!)
X86_TARGETS_DESC=	Build only x86 system targets
STATIC_LINK_DESC=	Statically link the executables
VDE_DESC=		vde dependency (for vde networking)
OPTIONS_DEFAULT=X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL PCAP NCURSES VDE
OPTIONS_SUB=	yes
X11_USE=	SDL=sdl2 XORG=x11,xext GNOME=gdkpixbuf2
X11_USES=	sdl
X11_CONFIGURE_ENABLE=	sdl
GTK3_LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
GTK3_USE=	GNOME=gdkpixbuf2,gtk30,vte3 XORG=x11,xext
GTK3_USES=	gettext gl
GTK3_CONFIGURE_OFF=	--disable-gtk --disable-vte
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
OPENGL_USE=	GL=gl
OPENGL_USES=	gl
OPENGL_CONFIGURE_OFF=	--disable-opengl
USBREDIR_BUILD_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_RUN_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_CONFIGURE_OFF=	--disable-usb-redir
PCAP_CONFIGURE_ON=	--enable-pcap
#PCAP_EXTRA_PATCHES=	${FILESDIR}/pcap-patch-qapi_net.json ${FILESDIR}/pcap-patch-net_net.c \
#			${FILESDIR}/pcap-patch-net_clients.h
VDE_LIB_DEPENDS=	libvdeplug.so:net/vde2
VDE_CONFIGURE_OFF=	--disable-vde
STATIC_LINK_CONFIGURE_ON=	--static
STATIC_LINK_PREVENTS=		GTK3 X11
STATIC_LINK_PREVENTS_MSG=	X11 ui cannot be built static
NCURSES_USES=		ncurses:base
SAMBA_USES=		samba:run # smbd
SAMBA_CONFIGURE_ON=	--smbd=${LOCALBASE}/sbin/smbd
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html \
			sphinx-build:textproc/py-sphinx
DOCS_USES=		makeinfo
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=1

PORTDOCS=	docs index.html interop/.buildinfo interop/* qemu-ga-ref.html qemu-ga-ref.txt \
	       	qemu-qmp-ref.html qemu-qmp-ref.txt specs/.buildinfo specs/* system/.buildinfo \
		system/* tools/.buildinfo tools/* user/.buildinfo user/*

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CFLAGS_amd64+=	-fPIC
CONFIGURE_ARGS=	--localstatedir=/var \
		--extra-ldflags=-L\"${LOCALBASE}/lib\" --enable-debug \
		--prefix=${PREFIX} --cc=${CC} --enable-netmap --enable-docs --disable-kvm \
		--disable-linux-user --disable-linux-aio --disable-xen \
		--enable-debug-info --python=${PYTHON_CMD} \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"
INSTALLS_ICONS=	yes

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

# -lprocstat actually only _needs_ -lelf after r249666 or r250870 (MFC)
# but it shouldn't matter much
post-patch:
#	@${REINPLACE_CMD} -e '/LIBS/s|-lprocstat|-lprocstat -lelf|' \
#		 -e '/libusb/s/ --atleast-version=1\.0\.[0-9]*//' \
#		${WRKSRC}/configure
#	@${REINPLACE_CMD} -E \
#		-e "s|^(CFLAGS=).*|\1${CFLAGS} -fno-strict-aliasing -I.|" \
#		-e "s|^(LDFLAGS=).*|\1${LDFLAGS}|" \
#		${WRKSRC}/Makefile

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
