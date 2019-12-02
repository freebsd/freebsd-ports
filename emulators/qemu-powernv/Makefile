# $FreeBSD$

PORTNAME=	qemu-powernv
PORTVERSION=	3.0.50
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://people.freebsd.org/~kbowling/distfiles/

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Fork of QEMU with experimental PowerNV emulation support

LICENSE=	GPLv2

BUILD_DEPENDS=		${LOCALBASE}/lib/libfdt.so:sysutils/dtc

USES=		bison:build compiler:c11 gmake gnome libtool makeinfo \
		pkgconfig python:build tar:bz2 xorg
USE_XORG=	pixman
USE_GNOME=	glib20

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--target-list=ppc64-softmmu \
		--cc=${CC} \
		--disable-curl \
		--disable-docs \
		--disable-gtk \
		--disable-gcrypt \
		--disable-kvm \
		--disable-libssh2 \
		--disable-linux-aio \
		--disable-linux-user \
		--disable-vnc \
		--disable-sdl \
		--disable-nettle \
		--disable-gnutls \
		--disable-vte \
		--disable-xen \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\" \
		--extra-ldflags=-L\"${LOCALBASE}/lib\" \
		--localstatedir=/var \
		--datadir=${DATADIR} \
		--python=${PYTHON_CMD}

PLIST_FILES=	bin/qemu-system-powernv \
		${DATADIR}/qemu/skiboot.lid \
		${DATADIR}/qemu/slof.bin \
		${DATADIR}/qemu/spapr-rtas.bin

# remap names to avoid conflicts with mainline port
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppc64-softmmu/qemu-system-ppc64 ${STAGEDIR}${PREFIX}/bin/qemu-system-powernv
	${MKDIR} ${STAGEDIR}${DATADIR}/qemu
	${INSTALL_DATA} ${WRKSRC}/pc-bios/skiboot.lid ${STAGEDIR}${DATADIR}/qemu/skiboot.lid
	${INSTALL_DATA} ${WRKSRC}/pc-bios/slof.bin ${STAGEDIR}${DATADIR}/qemu/slof.bin
	${INSTALL_DATA} ${WRKSRC}/pc-bios/spapr-rtas.bin ${STAGEDIR}${DATADIR}/qemu/spapr-rtas.bin

.include <bsd.port.mk>
