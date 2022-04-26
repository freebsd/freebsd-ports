PORTNAME=	qemu
DISTVERSION=	5.2.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
PKGNAMESUFFIX=	5
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU CPU Emulator - 5.X.X branch ${${FLAVOR}_COMMENT}

LICENSE=	GPLv2

DEPRECATED=	Use emulators/qemu6 or emulators/qemu
EXPIRATION_DATE=	2022-06-30

ONLY_FOR_ARCHS=	i386 amd64 powerpc powerpc64 powerpc64 powerpc64le

BUILD_DEPENDS=	bash:shells/bash \
		sphinx-build:textproc/py-sphinx
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnettle.so:security/nettle \
		libpcre2-8.so:devel/pcre2 \
		libzstd.so:archivers/zstd

FLAVORS=			default nox11
default_CONFLICTS_INSTALL=	qemu-devel qemu-nox11 qemu42 qemu5
nox11_PKGNAMESUFFIX=		5-nox11
nox11_CONFLICTS_INSTALL=	qemu qemu-devel qemu42 qemu5
nox11_COMMENT=			(without X11)

USES=		bison compiler:c11 cpe gmake gnome iconv:wchar_t ninja perl5 \
		pkgconfig python:build tar:xz xorg
USE_GNOME=	cairo glib20 libxml2
USE_PERL5=	build
USE_PYTHON=	distutils noflavors
USE_XORG=	pixman

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc=${CC} \
		--disable-kvm \
		--disable-linux-aio \
		--disable-linux-user \
		--disable-xen \
		--enable-debug \
		--enable-debug-info \
		--enable-netmap \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\" \
		--extra-ldflags=-L\"${LOCALBASE}/lib\" \
		--extra-ldflags=-L\"/usr/lib\" \
		--localstatedir=/var \
		--prefix=${PREFIX} \
		--python=${PYTHON_CMD}

CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
WITHOUT_CPU_CFLAGS=	yes #to avoid problems with register allocation

CONFLICTS_INSTALL=	qemu qemu-devel qemu-nox11 qemu42 qemu5

PORTSCOUT=	limit:^5\.

PORTDOCS=	docs index.html interop/* interop/.buildinfo specs/* \
		specs/.buildinfo system/* system/.buildinfo tools/* \
		tools/.buildinfo user/* user/.buildinfo

OPTIONS_DEFINE=			CAPSTONE CDROM_DMA CURL DOCS GNUTLS GTK3 JPEG \
				OPENGL PNG SAMBA SASL STATIC_LINK USBREDIR VDE \
				X11 X86_TARGETS
OPTIONS_DEFAULT=		CAPSTONE CDROM_DMA CURL GNUTLS GTK3 JPEG \
				NCURSES_DEFAULT OPENGL PNG SASL VDE X11
OPTIONS_SINGLE=			NCURSES
OPTIONS_SINGLE_NCURSES=		NCURSES_BASE NCURSES_DEFAULT NCURSES_PORT
.if ${FLAVOR:U} == nox11
OPTIONS_EXCLUDE:=		GTK3 X11
.endif
OPTIONS_SUB=			yes
CAPSTONE_DESC=			Disassembly framework support
CDROM_DMA_DESC=			IDE CDROM DMA
GNUTLS_DESC=			gnutls dependency (vnc encryption)
JPEG_DESC=			jpeg dependency (vnc lossy compression)
NCURSES_BASE_DESC=		Depend on ncurses in base
NCURSES_DEFAULT_DESC=		Depend on ncurses (ports if installed, otherwise base)
NCURSES_PORT_DESC=		Depend on devel/ncurses in ports
PNG_DESC=			png dependency (vnc compression)
SAMBA_DESC=			samba dependency (for -smb)
SASL_DESC=			cyrus-sasl dependency (vnc encryption)
STATIC_LINK_DESC=		Statically link the executables
USBREDIR_DESC=			usb device network redirection (experimental!)
VDE_DESC=			vde dependency (for vde networking)
X86_TARGETS_DESC=		Build only x86 system targets
CAPSTONE_LIB_DEPENDS=		libcapstone.so:devel/capstone4
CAPSTONE_CONFIGURE_ON=		--enable-capstone=system \
				--extra-cflags=-I${LOCALBASE}/include/capstone
CAPSTONE_CONFIGURE_OFF=		--disable-capstone
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=		--disable-curl
DOCS_USES=			makeinfo
DOCS_CONFIGURE_ENABLE=		docs
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=		--disable-gnutls
GTK3_LIB_DEPENDS=		libxkbcommon.so:x11/libxkbcommon
GTK3_USES=			gettext gl
GTK3_USE=			GNOME=gdkpixbuf2,gtk30,vte3 \
				XORG=x11,xext
GTK3_CONFIGURE_OFF=		--disable-gtk \
				--disable-vte
JPEG_USES=			jpeg
JPEG_CONFIGURE_OFF=		--disable-vnc-jpeg
NCURSES_BASE_USES=		ncurses:base
NCURSES_DEFAULT_USES=		ncurses
NCURSES_PORT_USES=		ncurses:port
OPENGL_USES=			gl
OPENGL_USE=			GL=gl
OPENGL_CONFIGURE_OFF=		--disable-opengl
PNG_LIB_DEPENDS=		libpng.so:graphics/png
PNG_CONFIGURE_OFF=		--disable-vnc-png
SAMBA_USES=			samba:run # smbd
SAMBA_CONFIGURE_ON=		--smbd=${LOCALBASE}/sbin/smbd
SASL_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_OFF=		--disable-vnc-sasl
STATIC_LINK_PREVENTS=		GTK3 X11
STATIC_LINK_PREVENTS_MSG=	X11 ui cannot be built static
STATIC_LINK_CONFIGURE_ON=	--static
USBREDIR_BUILD_DEPENDS=		usbredir>=0.6:net/usbredir
USBREDIR_RUN_DEPENDS=		usbredir>=0.6:net/usbredir
USBREDIR_CONFIGURE_OFF=		--disable-usb-redir
VDE_LIB_DEPENDS=		libvdeplug.so:net/vde2
VDE_CONFIGURE_OFF=		--disable-vde
X11_USES=			sdl
X11_USE=			GNOME=gdkpixbuf2 \
				SDL=sdl2 \
				XORG=x11,xext
X11_CONFIGURE_ENABLE=		sdl

.include <bsd.port.options.mk>

.if !defined(STRIP) || ${STRIP} == ""
CONFIGURE_ARGS+=	--disable-strip
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

do-build:
	cd ${WRKSRC} && ${GMAKE}

do-install:
	cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
