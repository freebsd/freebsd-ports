# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	0.d${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	emulators devel
PKGNAMESUFFIX=	-cheri

MAINTAINER=	brooks@FreeBSD.org
COMMENT?=	QEMU emulator with CHERI CPU support

# XXX: disabling gnutls doesn't work so depend on it to avoid breakage.
LIB_DEPENDS=	libcapstone.so:devel/capstone3 \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libgnutls.so:security/gnutls \
		libnettle.so:security/nettle
RUN_DEPENDS=	qemu-system-i386:emulators/qemu

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_TUPLE=	CTSRD-CHERI:qemu:${QEMU_COMMIT} \
		CTSRD-CHERI:dtc:${DTC_COMMIT}:dtc/dtc \
		CTSRD-CHERI:libslirp:${LIBSLIRP_COMMIT}:libslirp/slirp \
		qemu:keycodemapdb:6b3d716:qemu/ui/keycodemapdb \

HAS_CONFIGURE=	yes
USES=	compiler:c11 gettext-runtime gl gmake gnome libtool makeinfo pkgconfig \
	python:build xorg
USE_XORG=	pixman
USE_GNOME+=	glib20 libxml2
USE_GL+=	gbm
ONLY_FOR_ARCHS=	amd64 powerpc64

OPTIONS_DEFINE=	DOCS

.include "Makefile.snapshot"

CONFIGURE_ARGS+= \
		--target-list=cheri128-softmmu,cheri128magic-softmmu,riscv64cheri-softmmu \
		--disable-curl \
		--disable-git-update \
		--disable-gtk \
		--disable-linux-user \
		--disable-linux-aio \
		--disable-kvm \
		--disable-opengl \
		--disable-vnc-png \
		--disable-sdl \
		--disable-vte \
		--disable-xen \
		--smbd=${LOCALBASE}/sbin/smbd \
		--extra-cflags="-g ${EXTRA_CFLAGS}" \
		--localstatedir=/var
EXTRA_CFLAGS=	-DCHERI_UNALIGNED

QEMU_SYSTEM_CHERI?=	qemu-system${PKGNAMESUFFIX}
PLIST=	/dev/null
PLIST_FILES=	bin/qemu-system-cheri128 \
		bin/qemu-system-cheri128magic \
		bin/qemu-system-riscv64cheri

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cheri128-softmmu/qemu-system-cheri128 \
	    ${WRKSRC}/cheri128magic-softmmu/qemu-system-cheri128magic \
	    ${WRKSRC}/riscv64cheri-softmmu/qemu-system-riscv64cheri \
	    ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
