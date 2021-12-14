# Created by: Juergen Lock <nox@jelal.kn-bremen.de>

PORTNAME=	qemu
PORTVERSION=	6.1.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU CPU Emulator ${${FLAVOR}_COMMENT}

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
.if ${FLAVOR:U} != tools
LIB_DEPENDS+=	libfdt.so:sysutils/dtc \
		libzstd.so:archivers/zstd
.endif
.if (${FLAVOR:U} != nox11 && ${FLAVOR:U} != tools)
LIB_DEPENDS+=	libepoxy.so:graphics/libepoxy
.endif

FLAVORS=	default nox11 tools
FLAVOR?=	${FLAVORS:[1]}
default_CONFLICTS_INSTALL=	qemu5* qemu42 qemu-devel qemu-nox11 qemu-tools qemu-utils
nox11_PKGNAMESUFFIX=		-nox11
nox11_CONFLICTS_INSTALL=	qemu5* qemu42 qemu-devel qemu
nox11_COMMENT=				(without X11)
tools_PKGNAMESUFFIX=		-tools
tools_COMMENT=				(tools only)
tools_CONFLICTS_INSTALL=	qemu5* qemu42 qemu-devel qemu-nox11 qemu qemu-utils
tools_DESCR=	${.CURDIR}/pkg-descr-tools
tools_PLIST=	${.CURDIR}/pkg-plist-tools

USES=	cpe gmake gnome ninja perl5 pkgconfig python:build tar:xz
USE_GNOME=	glib20
USE_PERL5=	build
.if ${FLAVOR:U} != tools
ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64 powerpc64le
USES+=		iconv:wchar_t
.endif
.if (${FLAVOR:U} != nox11 && ${FLAVOR:U} != tools)
USE_GNOME+=	cairo
.endif

HAS_CONFIGURE=	yes

OPTIONS_SINGLE=	NCURSES
OPTIONS_SINGLE_NCURSES=	NCURSES_DEFAULT NCURSES_BASE NCURSES_PORT
OPTIONS_DEFINE=	SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL VDE \
		CDROM_DMA USBREDIR X86_TARGETS STATIC_LINK DOCS ISCSI CAPSTONE DEBUG \
		STRIP
OPTIONS_DEFAULT=X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL NCURSES_DEFAULT VDE
.if ${FLAVOR:U} == nox11
OPTIONS_EXCLUDE:=	GTK3 X11
.endif
.if ${FLAVOR:U} == tools
OPTIONS_EXCLUDE:=	SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL VDE \
		CDROM_DMA USBREDIR X86_TARGETS STATIC_LINK ISCSI CAPSTONE DEBUG \
		NCURSES_DEFAULT NCURSES_BASE NCURSES_PORT NCURSES
.endif
OPTIONS_SUB=	yes
CAPSTONE_DESC=		Disassembly framework support
CDROM_DMA_DESC=		IDE CDROM DMA
GNUTLS_DESC=		gnutls dependency (vnc encryption)
ISCSI_DESC=		libiscsi dependency (iSCSI client for emulated drives)
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
DEBUG_CONFIGURE_ON=	--enable-debug
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_CONFIGURE_ENABLE=	docs
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
STRIP_CONFIGURE_OFF=	--disable-strip
USBREDIR_BUILD_DEPENDS=	usbredir>=0.6:net/usbredir
USBREDIR_CONFIGURE_OFF=	--disable-usb-redir
USBREDIR_RUN_DEPENDS=	usbredir>=0.6:net/usbredir
VDE_CONFIGURE_OFF=	--disable-vde
VDE_LIB_DEPENDS=	libvdeplug.so:net/vde2
X11_CONFIGURE_ENABLE=	sdl
X11_USE=	SDL=sdl2 XORG=x11,xext GNOME=gdkpixbuf2
X11_USES=	sdl
.if (empty(FLAVOR) || ${FLAVOR:U} == default || ${FLAVOR:U} == nox11) && (${FLAVOR:U} != tools || ${PKGNAMESUFFIX} != "-guest-agent")
X86_TARGETS_USE_OFF=	XORG=pixman,x11
X86_TARGETS_USES_OFF=	xorg
X86_TARGETS_CONFIGURE_ON=	--target-list='i386-softmmu i386-bsd-user x86_64-softmmu x86_64-bsd-user'
.endif

PORTDOCS=	.buildinfo _static/* about/* devel/* docs genindex.html \
		index.html interop/* objects.inv search.html searchindex.js \
		specs/* system/* tools/* user/*

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS+=--localstatedir=/var --extra-ldflags=-L/usr/lib \
		--extra-ldflags=-L${LOCALBASE}/lib \
		--prefix=${PREFIX} --cc=${CC} --disable-kvm \
		--disable-linux-user --disable-linux-aio --disable-xen \
		--python=${PYTHON_CMD} \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"

.if ${FLAVOR:U} != tools
CONFIGURE_ARGS+=--enable-netmap --enable-fdt=system
.endif
.if ${FLAVOR:U} == tools
CONFIGURE_ARGS+=--disable-netmap --disable-system --disable-user  \
			--disable-nettle --disable-gcrypt --disable-curses \
			--disable-vnc --disable-virtfs --disable-brlapi \
			--disable-fdt --disable-rdma --disable-guest-agent \
			--disable-cap-ng --disable-attr \
			--disable-vhost-net --disable-spice \
			--disable-rbd --disable-libnfs \
			--disable-smartcard --disable-libusb \
			--disable-lzo --disable-snappy \
			--disable-bzip2 --disable-seccomp \
			--disable-coroutine-pool --disable-glusterfs \
			--disable-tpm --disable-numa \
			--disable-blobs --enable-tools
.endif

.include <bsd.port.options.mk>

.if (empty(FLAVOR) || ${FLAVOR:U} == default || ${FLAVOR:U} == nox11) && (${FLAVOR:U} != tools || ${PKGNAMESUFFIX} != "-guest-agent")
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
.endif

post-patch-CDROM_DMA-off:
	@${REINPLACE_CMD} -e '/USE_DMA_CDROM/d' ${WRKSRC}/include/hw/ide/internal.h

do-build:
	cd ${WRKSRC} && ${GMAKE}

do-install:
	cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${GMAKE} install

.if !target(post-install)
post-install:
.if ${FLAVOR:U} != tools
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
.endif

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif

.include <bsd.port.mk>
