# $FreeBSD$

PKGNAMESUFFIX=	-utils

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	QEMU userland utilities

HAS_CONFIGURE=	yes
USES=		compiler:c11 cpe gmake pkgconfig perl5 python:build tar:xz
USES+=		gettext-runtime
USE_GNOME+=	glib20
MAKE_ENV+=	BSD_MAKE="${MAKE}" PREFIX=${PREFIX}
CONFLICTS_INSTALL=	qemu-[0-9]* qemu-devel-* qemu-sbruno-*

OPTIONS_SLAVE=	DOCS
OPTIONS_EXCLUDE=	SAMBA X11 GTK3 OPENGL GNUTLS SASL JPEG PNG CURL \
		CDROM_DMA PCAP USBREDIR GNS3 X86_TARGETS \
		STATIC_LINK NCURSES VDE
MASTERDIR=	${.CURDIR}/../qemu
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr
EXTRA_PATCHES=	${.CURDIR}/files/patch-configure
PKGMESSAGE=

PORTDOCS=	qemu-doc.html qemu-doc.txt

CONFIGURE_ARGS?=--localstatedir=/var --extra-ldflags=-L\"${LOCALBASE}/lib\" \
		--disable-libssh2 \
		--mandir=${MANPREFIX}/man \
		--prefix=${PREFIX} --cc=${CC} --disable-kvm \
		--disable-linux-user --disable-linux-aio --disable-xen \
		--python=${PYTHON_CMD} \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\" \
		--disable-curl \
		--disable-gnutls \
		--disable-gtk \
		--disable-vte \
		--disable-vnc-jpeg \
		--disable-opengl \
		--disable-usb-redir \
		--disable-sdl \
		--disable-system \
		--disable-user \
		--disable-guest-agent \
		--disable-nettle \
		--disable-gcrypt \
		--disable-curses \
		--disable-vnc \
		--disable-virtfs \
		--disable-brlapi \
		--disable-fdt \
		--disable-bluez \
		--disable-kvm \
		--disable-rdma \
		--disable-vde \
		--disable-netmap \
		--disable-cap-ng \
		--disable-attr \
		--disable-vhost-net \
		--disable-spice \
		--disable-rbd \
		--disable-libiscsi \
		--disable-libnfs \
		--disable-smartcard \
		--disable-libusb \
		--disable-usb-redir \
		--disable-lzo \
		--disable-snappy \
		--disable-bzip2 \
		--disable-seccomp \
		--disable-coroutine-pool \
		--disable-glusterfs \
		--disable-tpm \
		--disable-numa \
		--disable-blobs

LIB_DEPENDS=

# qemu-utils must patch Makefile during pre-configure, because the master port
# also patches Makefile.  We can't use EXTRA_PATCHES, because that happens
# before do-patch, and causes a conflict with the master port's patch. And we
# can't use post-patch, because the master port also defines that target.
pre-configure:
	${PATCH} ${WRKSRC}/Makefile ${.CURDIR}/files/patch-Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
	@${RMDIR} ${STAGEDIR}${DATADIR}

.include "${MASTERDIR}/Makefile"
