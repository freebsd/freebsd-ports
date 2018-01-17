# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	2.7.50
PORTREVISION=	20180105
CATEGORIES=	emulators
PKGNAMESUFFIX=	-riscv

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	QEMU with RISC-V (RV64GC, RV32GC) emulation support

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64
BROKEN_powerpc64=	fails to compile: async.c: internal compiler error: Segmentation fault

USE_GITHUB=	yes
GH_TUPLE=	riscv:riscv-qemu:8d56aad \
		qemu:dtc:65cc4d2:dtc/dtc

HAS_CONFIGURE=	yes
USES=	gmake libtool makeinfo pkgconfig python:2.7,build
USE_XORG=	pixman
USE_GNOME+=	glib20

CONFIGURE_ARGS+=--target-list=riscv64-softmmu,riscv32-softmmu \
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1100000
IGNORE=	does not build
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/riscv32-softmmu/qemu-system-riscv32 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/riscv64-softmmu/qemu-system-riscv64 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
