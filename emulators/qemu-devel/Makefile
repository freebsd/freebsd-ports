PORTNAME=	qemu
DISTVERSION=	6.1.0.20210928
PORTREVISION=	2
CATEGORIES=	emulators
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU CPU Emulator - development version

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 powerpc powerpc64 powerpc64 powerpc64le

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
		bash:shells/bash
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnettle.so:security/nettle \
		libpcre2-8.so:devel/pcre2 \
		libzstd.so:archivers/zstd

USES=		bison compiler:c11 cpe gmake gnome iconv:wchar_t ninja perl5 \
		pkgconfig python:build tar:xz xorg
USE_GITLAB=	yes
USE_GNOME=	cairo glib20 libxml2
USE_PERL5=	build
USE_PYTHON=	distutils noflavors
USE_XORG=	pixman

GL_COMMIT=	de8ed1055c2ce18c95f597eb10df360dcb534f99
GL_TUPLE=	qemu-project:keycodemapdb:d21009b1c9f94b740ea66be8e48a1d8ad8124023:keycodemapdb/ui/keycodemapdb \
		qemu-project:dtc:e33ce1d6a8c7e54e3ad12cff33690b6da0aee1dc:dtc/dtc \
		qemu-project:meson:5fa0fd3b473f792bd7333cf6ae6e2f4c851b6108:meson/meson \
		qemu-project:berkeley-softfloat-3:b64af41c3276f97f0e181920400ee056b9c88037:berkeleysoftfloat3/tests/fp/berkeley-softfloat-3 \
		qemu-project:berkeley-testfloat-3:5a59dcec19327396a011a17fd924aed4fec416b3:berkeleytestfloat3/tests/fp/berkeley-testfloat-3

#.if !defined(PKGNAMESUFFIX) || (${PKGNAMESUFFIX} != "-utils" && ${PKGNAMESUFFIX} != "-guest-agent")
#.endif

HAS_CONFIGURE=	yes

OPTIONS_SINGLE=	NCURSES
OPTIONS_SINGLE_NCURSES=	NCURSES_DEFAULT NCURSES_BASE NCURSES_PORT
OPTIONS_DEFINE=	SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL VDE \
		CDROM_DMA USBREDIR X86_TARGETS STATIC_LINK DOCS CAPSTONE
OPTIONS_DEFAULT=X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL NCURSES_DEFAULT VDE \
		CAPSTONE
OPTIONS_SUB=	yes
CAPSTONE_DESC=		Disassembly framework support
CDROM_DMA_DESC=		IDE CDROM DMA
GNUTLS_DESC=		gnutls dependency (vnc encryption)
JPEG_DESC=		jpeg dependency (vnc lossy compression)
NCURSES_DEFAULT_DESC=	Depend on ncurses (ports if installed, otherwise base)
NCURSES_BASE_DESC=	Depend on ncurses in base
NCURSES_PORT_DESC=	Depend on devel/ncurses in ports
PNG_DESC=		png dependency (vnc compression)
SAMBA_DESC=		samba dependency (for -smb)
SASL_DESC=		cyrus-sasl dependency (vnc encryption)
STATIC_LINK_DESC=	Statically link the executables
USBREDIR_DESC=		usb device network redirection (experimental!)
VDE_DESC=		vde dependency (for vde networking)
X86_TARGETS_DESC=	Build only x86 system targets
CAPSTONE_CONFIGURE_ON=	--enable-capstone=system --extra-cflags=-I${LOCALBASE}/include/capstone
CAPSTONE_CONFIGURE_OFF=	--disable-capstone
CAPSTONE_LIB_DEPENDS=	libcapstone.so:devel/capstone4
CURL_CONFIGURE_OFF=	--disable-curl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
DOCS_CONFIGURE_ENABLE=	docs
DOCS_USES=		makeinfo
GNUTLS_CONFIGURE_OFF=	--disable-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GTK3_CONFIGURE_OFF=	--disable-gtk --disable-vte
GTK3_LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
GTK3_USE=	GNOME=gdkpixbuf2,gtk30,vte3 XORG=x11,xext
GTK3_USES=	gettext gl
JPEG_CONFIGURE_OFF=	--disable-vnc-jpeg
JPEG_USES=		jpeg
NCURSES_DEFAULT_USES=	ncurses
NCURSES_BASE_USES=	ncurses:base
NCURSES_PORT_USES=	ncurses:port
OPENGL_CONFIGURE_OFF=	--disable-opengl
OPENGL_USE=	GL=gbm,gl
OPENGL_USES=	gl
PNG_CONFIGURE_OFF=	--disable-vnc-png
PNG_LIB_DEPENDS=	libpng.so:graphics/png
SAMBA_CONFIGURE_ON=	--smbd=${LOCALBASE}/sbin/smbd
SASL_CONFIGURE_OFF=	--disable-vnc-sasl
SAMBA_USES=		samba:run # smbd
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

PORTDOCS=	.buildinfo _static/* about/* devel/* docs genindex.html \
		index.html interop/* objects.inv search.html searchindex.js \
	       	specs/* system/* tools/* user/*

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS=	--localstatedir=/var --extra-ldflags=-L\"/usr/lib\" \
		--extra-ldflags=-L\"${LOCALBASE}/lib\" --enable-debug \
		--prefix=${PREFIX} --cc=${CC} --enable-netmap --disable-kvm \
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
CFLAGS+=	-D_CALL_SYSV
MAKE_ARGS+=	ARCH=ppc
USE_GCC=	yes
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

.if !target(post-install)
post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif

.include <bsd.port.mk>
