# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	2.13.0
PORTREVISION=	20180622
CATEGORIES=	emulators
PKGNAMESUFFIX=	-riscv

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	QEMU with RISC-V (RV64GC, RV32GC) emulation support

LICENSE=	GPLv2

DEPRECATED=	The development has been moved to the upstream
EXPIRATION_DATE=	2019-06-30

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64
BROKEN_powerpc64=	fails to compile: async.c: internal compiler error: Segmentation fault

USES=	gmake libtool makeinfo pkgconfig python:2.7,build

USE_GITHUB=	yes
GH_TUPLE=	riscv:riscv-qemu:360a780 \
		qemu:dtc:e543880:dtc/dtc \
		qemu:keycodemapdb:6b3d716:keycodemapdb/ui/keycodemapdb

HAS_CONFIGURE=	yes
USE_XORG=	pixman
USE_GNOME=	glib20

CONFIGURE_ARGS=--target-list=riscv64-softmmu,riscv32-softmmu \
		--cc=${CC} \
		--enable-fdt \
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
		--python=${PYTHON_CMD}

PLIST_FILES=	bin/qemu-system-riscv32 \
		bin/qemu-system-riscv64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/riscv32-softmmu/qemu-system-riscv32 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/riscv64-softmmu/qemu-system-riscv64 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
