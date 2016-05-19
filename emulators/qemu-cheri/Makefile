# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	0.d${SNAPDATE}
CATEGORIES=	emulators devel
PKGNAMESUFFIX?=	-cheri

MAINTAINER=	brooks@FreeBSD.org
COMMENT?=	QEMU emulator with CHERI CPU support

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	${QEMU_COMMIT}

HAS_CONFIGURE=	yes
USES=	gmake libtool makeinfo pkgconfig python:2,build
USE_XORG=	pixman
USE_GNOME+=	glib20
#MAKE_ENV+=	BSD_MAKE="${MAKE}"
ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64

CONFLICTS_INSTALL=	qemu-[0-9]* qemu-devel-[0-9]* qemu-sbruno-[0-9]*

.include "Makefile.snapshot"

CONFIGURE_ARGS+= \
		--target-list=cheri-softmmu \
		--disable-gtk \
		--disable-linux-user \
		--disable-linux-aio \
		--disable-kvm \
		--disable-smartcard-nss \
		--disable-vte \
		--disable-xen \
		--extra-cflags="-g ${EXTRA_CFLAGS}" \
		--localstatedir=/var

.include <bsd.port.mk>
