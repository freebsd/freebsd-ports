# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	0.d${SNAPDATE}
CATEGORIES=	emulators devel
PKGNAMESUFFIX=	-cheri

MAINTAINER=	brooks@FreeBSD.org
COMMENT?=	QEMU emulator with CHERI CPU support

# XXX: disabling gnutls doesn't work so depend on it to avoid breakage.
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libnettle.so:security/nettle
RUN_DEPENDS=	qemu-system-i386:emulators/qemu

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	${QEMU_COMMIT}

HAS_CONFIGURE=	yes
USES=	gettext-runtime gmake libtool makeinfo pkgconfig python:2.7,build
USE_XORG=	pixman
USE_GNOME+=	glib20
ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64
BROKEN_FreeBSD_10=	Default toolchain lacks support for .cfi_sections

.include "Makefile.snapshot"

CONFIGURE_ARGS+= \
		--target-list=cheri128-softmmu,cheri128magic-softmmu,cheri256-softmmu \
		--disable-curl \
		--disable-gtk \
		--disable-libssh2 \
		--disable-linux-user \
		--disable-linux-aio \
		--disable-kvm \
		--disable-vnc-png \
		--disable-sdl \
		--disable-vte \
		--disable-xen \
		--extra-cflags="-g ${EXTRA_CFLAGS}" \
		--localstatedir=/var

QEMU_SYSTEM_CHERI?=	qemu-system${PKGNAMESUFFIX}
PLIST=	/dev/null
PLIST_FILES=	bin/qemu-system-cheri128 \
		bin/qemu-system-cheri128magic \
		bin/qemu-system-cheri256

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cheri128-softmmu/qemu-system-cheri128 \
	    ${WRKSRC}/cheri128magic-softmmu/qemu-system-cheri128magic \
	    ${WRKSRC}/cheri256-softmmu/qemu-system-cheri256 \
	    ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
