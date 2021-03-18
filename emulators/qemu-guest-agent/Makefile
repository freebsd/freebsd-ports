# Created by: Kaltashkin Eugene <zhecka@gmail.com>
# $FreeBSD$

PORTNAME=	qemu
DISTVERSION=	5.0.1
CATEGORIES=	emulators
MASTER_SITES=	https://download.qemu.org/
PKGNAMESUFFIX=	-guest-agent

MAINTAINER=	zhecka@gmail.com
COMMENT=	QEMU guest-agent utilities

LICENSE=	GPLv2

DIST_SUBDIR=	qemu/${PORTVERSION}
FILESDIR=	${.CURDIR}/files
HAS_CONFIGURE=	yes
USES=		compiler:c++11-lang gmake gnome pkgconfig python:build tar:xz
USE_GNOME=	glib20
USE_RC_SUBR=	qemu-guest-agent
MAKE_ENV+=	BSD_MAKE="${MAKE}" PREFIX=${PREFIX}

OPTIONS_EXCLUDE=SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL \
		CDROM_DMA PCAP USBREDIR GNS3 X86_TARGETS DOCS\
		STATIC_LINK NCURSES VDE

PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

CONFIGURE_ARGS?=--localstatedir=/var --extra-ldflags=-L\"${LOCALBASE}/lib\" \
		--mandir=${MANPREFIX}/man \
		--prefix=${PREFIX} --cc=${CC} --disable-kvm \
		--python=${PYTHON_CMD} \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"\ -DBSD_GUEST_AGENT\ -DFREEBSD \
		--disable-blobs \
		--disable-system \
		--disable-user \
		--disable-linux-user \
		--disable-bsd-user \
		--disable-docs \
		--enable-guest-agent \
		--disable-guest-agent-msi \
		--disable-pie \
		--disable-modules \
		--disable-module-upgrades \
		--disable-debug-tcg \
		--disable-debug-info \
		--disable-sparse \
		--disable-gnutls \
		--disable-nettle \
		--disable-gcrypt \
		--disable-auth-pam \
		--disable-sdl \
		--disable-sdl-image \
		--disable-gtk \
		--disable-vte \
		--disable-curses \
		--disable-iconv \
		--disable-vnc \
		--disable-vnc-sasl \
		--disable-vnc-jpeg \
		--disable-vnc-png \
		--disable-cocoa \
		--disable-virtfs \
		--disable-mpath \
		--disable-xen \
		--disable-xen-pci-passthrough \
		--disable-brlapi \
		--disable-curl \
		--disable-membarrier \
		--disable-fdt \
		--disable-kvm \
		--disable-hax \
		--disable-hvf \
		--disable-whpx \
		--disable-rdma \
		--disable-pvrdma \
		--disable-vde \
		--disable-netmap \
		--disable-linux-aio \
		--disable-linux-io-uring \
		--disable-cap-ng \
		--disable-attr \
		--disable-vhost-net \
		--disable-vhost-vsock \
		--disable-vhost-scsi \
		--disable-vhost-crypto \
		--disable-vhost-kernel \
		--disable-vhost-user \
		--disable-spice \
		--disable-rbd \
		--disable-libiscsi \
		--disable-libnfs \
		--disable-smartcard \
		--disable-libusb \
		--disable-live-block-migration \
		--disable-usb-redir \
		--disable-lzo \
		--disable-snappy \
		--disable-bzip2 \
		--disable-lzfse \
		--disable-zstd \
		--disable-seccomp \
		--disable-coroutine-pool \
		--disable-glusterfs \
		--disable-tpm \
		--disable-libssh \
		--disable-numa \
		--disable-libxml2 \
		--disable-tcmalloc \
		--disable-jemalloc \
		--disable-avx2 \
		--disable-avx512f \
		--disable-replication \
		--disable-opengl \
		--disable-virglrenderer \
		--disable-xfsctl \
		--disable-qom-cast-debug \
		--enable-tools \
		--disable-vxhs \
		--disable-bochs \
		--disable-cloop \
		--disable-dmg \
		--disable-qcow1 \
		--disable-vdi \
		--disable-vvfat \
		--disable-qed \
		--disable-parallels \
		--disable-sheepdog \
		--disable-crypto-afalg \
		--disable-capstone \
		--disable-debug-mutex \
		--disable-libpmem \
		--disable-xkbcommon

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
	@${RM} ${STAGEDIR}${PREFIX}/bin/qemu-nbd
	@${RM} ${STAGEDIR}${PREFIX}/bin/qemu-edid
	@${RM} ${STAGEDIR}${PREFIX}/bin/qemu-img
	@${RM} ${STAGEDIR}${PREFIX}/bin/qemu-io
	@${RMDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/qemu

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

.if ${OSVERSION} < 1200000
PKGMESSAGE=	${.CURDIR}/pkg-message-11
.else
PKGMESSAGE=	${.CURDIR}/pkg-message
.endif

PLIST_SUB+=	LINUXBOOT_DMA=""

# XXX need to disable usb host code on head while it's not ported to the
# new usb stack yet
post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|^(HOST_USB=)bsd|\1stub|" \
		${WRKSRC}/config-host.mak

.include <bsd.port.mk>
