PORTNAME=	qemu
DISTVERSION=	10.1.20250830
CATEGORIES=	emulators
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU CPU Emulator - development version
WWW=		https://www.qemu.org/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 powerpc powerpc64 powerpc64 powerpc64le

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
		bash:shells/bash
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libinotify.so:devel/libinotify \
		libzstd.so:archivers/zstd

USES=		bison compiler:c11 cpe gmake gnome iconv:wchar_t localbase:ldflags \
		ninja perl5 pkgconfig python:build shebangfix tar:xz xorg
USE_GITLAB=	yes
GL_ACCOUNT=	qemu-project
GL_TAGNAME=	91589bcd9fee0e66b241d04e5f37cd4f218187a2
GL_TUPLE=	qemu-project:keycodemapdb:f5772a62ec52591ff6870b7e8ef32482371f22c6:keycodemapdb/subprojects/keycodemapdb \
		qemu-project:dtc:b6910bec11614980a21e46fbccc35934b671bd81:dtc/subprojects/dtc \
		qemu-project:libvfio-user:0b28d205572c80b568a1003db2c8f37ca333e4d7:libvfio/subprojects/libvfio-user \
		qemu-project:meson:2cf1fa324069daa170c1f0d321c0f7d885fff670:meson/meson \
		qemu-project:berkeley-softfloat-3:b64af41c3276f97f0e181920400ee056b9c88037:berkeleysoftfloat3/subprojects/berkeley-softfloat-3 \
		qemu-project:berkeley-testfloat-3:e7af9751d9f9fd3b47911f51a5cfd08af256a9ab:berkeleytestfloat3/subprojects/berkeley-testfloat-3
USE_GNOME=	cairo glib20
USE_PERL5=	build
USE_PYTHON=	distutils noflavors
USE_XORG=	pixman

SHEBANG_FILES=	scripts/xml-preprocess.py

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --mandir=share/man --extra-ldflags=-L\"/usr/lib\" \
		--extra-ldflags=-L\"${LOCALBASE}/lib\" --enable-debug \
		--prefix=${PREFIX} --cc=${CC} --enable-netmap --disable-kvm \
		--disable-linux-user --disable-linux-aio --disable-xen \
		--enable-debug-info --python=${PYTHON_CMD} --disable-guest-agent \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"

CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PORTDOCS=	.buildinfo _static/* about/* dbus-dbusindex.html devel/* \
		docs genindex.html glossary.html index.html interop/* \
		objects.inv qapi-qga-index.html qapi-qmp-index.html \
		qapi-qsd-index.html search.html searchindex.js specs/* system/* \
		tools/* user/*

OPTIONS_DEFINE=	SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL VDE \
		CDROM_DMA USBREDIR X86_TARGETS STATIC_LINK DOCS CAPSTONE
OPTIONS_DEFAULT=X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL NCURSES_DEFAULT VDE \
		CAPSTONE
OPTIONS_SINGLE=	NCURSES
OPTIONS_SINGLE_NCURSES=	NCURSES_DEFAULT NCURSES_BASE NCURSES_PORT
OPTIONS_SUB=	yes

CAPSTONE_DESC=		Disassembly framework support
CDROM_DMA_DESC=		IDE CDROM DMA
GNUTLS_DESC=		gnutls dependency (vnc encryption)
JPEG_DESC=		jpeg dependency (vnc lossy compression)
NCURSES_BASE_DESC=	Depend on ncurses in base
NCURSES_DEFAULT_DESC=	Depend on ncurses (ports if installed, otherwise base)
NCURSES_PORT_DESC=	Depend on devel/ncurses in ports
PNG_DESC=		png dependency (vnc compression)
SAMBA_DESC=		samba dependency (for -smb)
SASL_DESC=		cyrus-sasl dependency (vnc encryption)
STATIC_LINK_DESC=	Statically link the executables
USBREDIR_DESC=		usb device network redirection (experimental!)
VDE_DESC=		vde dependency (for vde networking)
X86_TARGETS_DESC=	Build only x86 system targets

CAPSTONE_LIB_DEPENDS=	libcapstone.so:devel/capstone
CAPSTONE_CONFIGURE_ON=	--enable-capstone --extra-cflags=-I${LOCALBASE}/include/capstone
CAPSTONE_CONFIGURE_OFF=	--disable-capstone
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--disable-curl
DOCS_USES=		makeinfo
DOCS_CONFIGURE_ENABLE=	docs
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=	--disable-gnutls
GTK3_LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
GTK3_USES=	gettext gl
GTK3_USE=	GNOME=gdkpixbuf,vte3 XORG=x11,xext
GTK3_CONFIGURE_OFF=	--disable-gtk --disable-vte
JPEG_USES=		jpeg
JPEG_CONFIGURE_OFF=	--disable-vnc-jpeg
NCURSES_BASE_USES=	ncurses:base
NCURSES_DEFAULT_USES=	ncurses
NCURSES_PORT_USES=	ncurses:port
OPENGL_USES=	gl
OPENGL_USE=	GL=gbm
OPENGL_CONFIGURE_OFF=	--disable-opengl
PNG_LIB_DEPENDS=	libpng16.so:graphics/png
PNG_CONFIGURE_OFF=	--disable-vnc-png
SAMBA_USES=		samba:run # smbd
SAMBA_CONFIGURE_ON=	--smbd=${LOCALBASE}/sbin/smbd
SASL_CONFIGURE_OFF=	--disable-vnc-sasl
STATIC_LINK_PREVENTS=		GTK3 X11
STATIC_LINK_PREVENTS_MSG=	X11 ui cannot be built static
STATIC_LINK_CONFIGURE_ON=	--static
USBREDIR_BUILD_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_RUN_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_CONFIGURE_OFF=	--disable-usb-redir
VDE_CONFIGURE_OFF=	--disable-vde
X11_USES=	sdl
X11_USE=	SDL=sdl2 XORG=x11,xext GNOME=gdkpixbuf
X11_CONFIGURE_ENABLE=	sdl

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

.if ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--disable-bsd-user
MAKE_ARGS+=	ARCH=ppc64
PLIST_SUB+=	BSDUSER="@comment "
.else
PLIST_SUB+=	BSDUSER=""
.endif

PLIST_SUB+=	LINUXBOOT_DMA=""

post-extract:
	${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-softfloat-3/* \
		${WRKSRC}/subprojects/berkeley-softfloat-3/
	${CP} ${WRKSRC}/subprojects/packagefiles/berkeley-testfloat-3/* \
		${WRKSRC}/subprojects/berkeley-testfloat-3/

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
