# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	2.7.50
PORTREVISION=	20161221
CATEGORIES=	emulators
PKGNAMESUFFIX?=	-riscv

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	QEMU with RISC-V (RV64G, RV32G) emulation support

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	riscv
GH_PROJECT=	riscv-qemu
GH_TAGNAME=	21e3a7c

HAS_CONFIGURE=	yes
USES=	gmake libtool makeinfo pkgconfig python:2,build
USE_XORG=	pixman
USE_GNOME+=	glib20
ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64

CONFIGURE_ARGS+=--target-list=riscv64-softmmu,riscv32-softmmu \
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
