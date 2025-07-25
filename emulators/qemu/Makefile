PORTNAME=	qemu
DISTVERSION=	10.0.3
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	QEMU CPU Emulator ${${FLAVOR}_COMMENT}
WWW=		https://www.qemu.org/

LICENSE=	GPLv2

.if ${FLAVOR:U} != tools && ${FLAVOR:U} != guestagent
ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le
# We need to check if it build with other ARCHS
.endif

BUILD_DEPENDS=	bash:shells/bash
.if ${FLAVOR:U} != guestagent
LIB_DEPENDS+=	libzstd.so:archivers/zstd
.endif
.if ${FLAVOR:U} != tools && ${FLAVOR:U} != guestagent
LIB_DEPENDS+=	libfdt.so:sysutils/dtc \
		libinotify.so:devel/libinotify \
		libslirp.so:net/libslirp
.endif
.if (${FLAVOR:U} != nox11 && ${FLAVOR:U} != tools && ${FLAVOR:U} != guestagent)
LIB_DEPENDS+=	libepoxy.so:graphics/libepoxy
.endif
.if (${FLAVOR:U} != nox11 && ${FLAVOR:U} != tools && ${FLAVOR:U} != default)
PKGMESSAGE=	${.CURDIR}/pkg-message.guest-agent
.endif

FLAVORS=			default nox11 tools guestagent
FLAVOR?=			${FLAVORS:[1]}
default_CONFLICTS_INSTALL=	qemu-devel qemu-nox11 qemu-tools qemu-utils \
				qemu6* qemu7*
nox11_PKGNAMESUFFIX=		-nox11
nox11_CONFLICTS_INSTALL=	qemu qemu-devel qemu6* qemu7* qemu-guest-agent
nox11_COMMENT=			(without X11)
tools_PKGNAMESUFFIX=		-tools
tools_COMMENT=			(tools only)
tools_CONFLICTS_INSTALL=	qemu qemu-devel qemu-nox11 qemu-utils qemu6* \
				qemu70* qemu-guest-agent
tools_DESCR=			${.CURDIR}/pkg-descr-tools
tools_PLIST=			${.CURDIR}/pkg-plist-tools
guestagent_PKGNAMESUFFIX=		-guest-agent
guestagent_COMMENT=			(guest agent)
guestagent_DESCR=		${.CURDIR}/pkg-descr-ga
guestagent_PLIST=		${.CURDIR}/pkg-plist-ga
guestagent_CONFLICTS_INSTALL=	qemu qemu-devel qemu-nox11 qemu-tools qemu-utils qemu6* \
				qemu7* qemu-guest-agent

USES=		cpe gmake gnome ninja perl5 pkgconfig python:build shebangfix tar:xz
SHEBANG_FILES=	scripts/xml-preprocess.py
USE_GNOME=	glib20
USE_PERL5=	build
.if ${FLAVOR:U} != tools && ${FLAVOR:U} != guestagent
USES+=		iconv:wchar_t
.endif
.if (${FLAVOR:U} != nox11 && ${FLAVOR:U} != tools && ${FLAVOR:U} != guestagent)
USE_GNOME+=	cairo
.endif

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--cc=${CC} \
			--disable-kvm \
			--disable-linux-aio \
			--disable-linux-user \
			--disable-xen \
			--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\" \
			--extra-ldflags=-L${LOCALBASE}/lib \
			--extra-ldflags=-L/usr/lib \
			--localstatedir=/var \
			--mandir=${PREFIX}/share/man \
			--prefix=${PREFIX} \
			--python=${PYTHON_CMD}
.if ${FLAVOR:U} == guestagent
USE_RC_SUBR=		qemu-guest-agent
CONFIGURE_ARGS+=	--enable-guest-agent --disable-tools --disable-xkbcommon
.else
CONFIGURE_ARGS+=	--disable-guest-agent
.endif
.if ${FLAVOR:U} != tools && ${FLAVOR:U} != guestagent
CONFIGURE_ARGS+=	--enable-fdt=system \
			--enable-netmap
.endif
.if ${FLAVOR:U} == tools || ${FLAVOR:U} == guestagent
CONFIGURE_ARGS+=	--disable-attr \
			--disable-install-blobs \
			--disable-brlapi \
			--disable-bzip2 \
			--disable-cap-ng \
			--disable-coroutine-pool \
			--disable-curses \
			--disable-fdt \
			--disable-gcrypt \
			--disable-glusterfs \
			--disable-libnfs \
			--disable-libusb \
			--disable-lzo \
			--disable-netmap \
			--disable-nettle \
			--disable-numa \
			--disable-rbd \
			--disable-rdma \
			--disable-seccomp \
			--disable-smartcard \
			--disable-snappy \
			--disable-spice \
			--disable-system \
			--disable-tpm \
			--disable-user \
			--disable-vhost-net \
			--disable-virtfs \
			--disable-vnc
.endif
.if ${FLAVOR:U} == tools
CONFIGURE_ARGS+=	--enable-tools --enable-zstd
.endif

CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
WITHOUT_CPU_CFLAGS=	yes #to avoid problems with register allocation

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PORTDOCS=	.buildinfo _static/* about/* dbus-dbusindex.html devel/* docs \
		genindex.html glossary.html index.html interop/* objects.inv \
		qapi-qga-index.html qapi-qmp-index.html qapi-qsd-index.html \
		search.html searchindex.js specs/* system/* tools/* user/*

OPTIONS_DEFINE=			CAPSTONE CDROM_DMA CURL DEBUG DOCS GNUTLS GTK3 \
				ISCSI JPEG OPENGL PNG SAMBA SASL STATIC_LINK \
				STRIP USBREDIR VDE X11 X86_TARGETS
OPTIONS_DEFAULT=		CDROM_DMA CURL GNUTLS GTK3 JPEG NCURSES_DEFAULT \
				OPENGL PNG SASL VDE X11
OPTIONS_SINGLE=			NCURSES
OPTIONS_SINGLE_NCURSES=		NCURSES_BASE NCURSES_DEFAULT NCURSES_PORT
.if ${FLAVOR:U} == nox11
OPTIONS_EXCLUDE:=		GTK3 OPENGL X11
.endif
.if ${FLAVOR:U} == tools || ${FLAVOR:U} == guestagent
OPTIONS_EXCLUDE:=		CAPSTONE CDROM_DMA CURL DEBUG GNUTLS GTK3 ISCSI \
				JPEG NCURSES NCURSES_BASE NCURSES_DEFAULT \
				NCURSES_PORT OPENGL PNG SAMBA SASL STATIC_LINK \
				USBREDIR VDE X11 X86_TARGETS
.endif
OPTIONS_SUB=			yes
CAPSTONE_DESC=			Disassembly framework support
CDROM_DMA_DESC=			IDE CDROM DMA
GNUTLS_DESC=			gnutls dependency (vnc encryption)
ISCSI_DESC=			libiscsi dependency (iSCSI client for emulated drives)
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
CAPSTONE_LIB_DEPENDS=		libcapstone.so:devel/capstone
CAPSTONE_CONFIGURE_ON=		--enable-capstone \
				--extra-cflags=-I${LOCALBASE}/include/capstone
CAPSTONE_CONFIGURE_OFF=		--disable-capstone
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=		--disable-curl
DEBUG_CONFIGURE_ON=		--enable-debug
DOCS_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
				sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
DOCS_CONFIGURE_ENABLE=		docs
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=		--disable-gnutls
GTK3_LIB_DEPENDS=		libxkbcommon.so:x11/libxkbcommon
GTK3_USES=			gettext gl
GTK3_USE=			GNOME=gdkpixbuf,gtk30,vte3 \
				XORG=x11,xext
GTK3_CONFIGURE_OFF=		--disable-gtk \
				--disable-vte
ISCSI_LIB_DEPENDS=		libiscsi.so:net/libiscsi
ISCSI_CONFIGURE_OFF=		--disable-libiscsi
JPEG_USES=			jpeg
JPEG_CONFIGURE_OFF=		--disable-vnc-jpeg
NCURSES_BASE_USES=		ncurses:base
NCURSES_DEFAULT_USES=		ncurses
NCURSES_PORT_USES=		ncurses:port
OPENGL_USES=			gl
OPENGL_USE=			GL=gbm,gl
OPENGL_CONFIGURE_OFF=		--disable-opengl
PNG_LIB_DEPENDS=		libpng.so:graphics/png
PNG_CONFIGURE_OFF=		--disable-png
SAMBA_USES=			samba:run # smbd
SAMBA_CONFIGURE_ON=		--smbd=${LOCALBASE}/sbin/smbd
SASL_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_OFF=		--disable-vnc-sasl
STATIC_LINK_PREVENTS=		GTK3 X11
STATIC_LINK_PREVENTS_MSG=	X11 ui cannot be built static
STATIC_LINK_CONFIGURE_ON=	--static
STRIP_CONFIGURE_OFF=		--disable-strip
USBREDIR_BUILD_DEPENDS=		usbredir>=0.6:net/usbredir
USBREDIR_RUN_DEPENDS=		usbredir>=0.6:net/usbredir
USBREDIR_CONFIGURE_OFF=		--disable-usb-redir
VDE_LIB_DEPENDS=		libvdeplug.so:net/vde2
VDE_CONFIGURE_OFF=		--disable-vde
X11_USES=			sdl
X11_USE=			GNOME=gdkpixbuf \
				SDL=sdl2 \
				XORG=x11,xext
X11_CONFIGURE_ENABLE=		sdl
.if (empty(FLAVOR) || ${FLAVOR:U} == default || ${FLAVOR:U} == nox11) && \
	(${FLAVOR:U} != tools || ${PKGNAMESUFFIX} != "-guest-agent")
X86_TARGETS_LIB_DEPENDS_OFF=	libdw.so:devel/elfutils \
	liblzo2.so:archivers/lzo2
X86_TARGETS_USES_OFF=		xorg
X86_TARGETS_USE_OFF=		XORG=pixman,x11
X86_TARGETS_CONFIGURE_ON=	--target-list='i386-softmmu i386-bsd-user x86_64-softmmu x86_64-bsd-user'
.endif

.include <bsd.port.options.mk>

.if ${FLAVOR:U} == tools || ${FLAVOR:U} == guestagent
.if ${ARCH} == "i386" || ${ARCH} == "powerpc" || ${ARCH:Marmv?}
PLIST_SUB+=	NO_I386="@comment "
.else
PLIST_SUB+=	NO_I386=""
.endif
.endif

.if (empty(FLAVOR) || ${FLAVOR:U} == default || ${FLAVOR:U} == nox11) && \
	(${FLAVOR:U} != tools || ${PKGNAMESUFFIX} != "-guest-agent")
.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=x86_64
.endif

.if ${ARCH} == "powerpc"
CFLAGS+=	-D_CALL_SYSV
MAKE_ARGS+=	ARCH=ppc
USE_GCC=	yes
.endif

.if ${ARCH:Mpowerpc64*} || ${ARCH:Maarch64}
CONFIGURE_ARGS+=	--disable-bsd-user
MAKE_ARGS+=	ARCH=${ARCH:C/powerpc64.*/ppc64/}
PLIST_SUB+=	BSDUSER="@comment "
.else
PLIST_SUB+=	BSDUSER=""
.endif

PLIST_SUB+=	LINUXBOOT_DMA=""
.endif

post-patch:
.if ${FLAVOR:U} == tools
	@${REINPLACE_CMD} -e '/keymaps/d' ${WRKSRC}/pc-bios/meson.build
.endif

post-patch-CDROM_DMA-off:
	@${REINPLACE_CMD} -e '/USE_DMA_CDROM/d' ${WRKSRC}/hw/ide/ide-internal.h

do-build:
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER}

do-install:
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} DESTDIR=${STAGEDIR} ${GMAKE} install

.if !target(post-install)
post-install:
.if ${FLAVOR:U} != tools && ${FLAVOR:U} != guestagent
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif

.include <bsd.port.mk>
