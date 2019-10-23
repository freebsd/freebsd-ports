# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	0.d${SNAPDATE}
PORTREVISION=	0
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
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	${QEMU_COMMIT}
GH_TUPLE=	qemu:keycodemapdb:6b3d716:qemu/ui/keycodemapdb

HAS_CONFIGURE=	yes
USES=	compiler:c11 gettext-runtime gl gmake gnome libtool makeinfo pkgconfig \
	python:2.7,build xorg
USE_XORG=	pixman
USE_GNOME+=	glib20 libxml2
USE_GL+=	gbm
ONLY_FOR_ARCHS=	amd64 powerpc64

OPTIONS_DEFINE=	DOCS

.include "Makefile.snapshot"

CONFIGURE_ARGS+= \
		--target-list=cheri128-softmmu,cheri128magic-softmmu,cheri256-softmmu \
		--disable-curl \
		--disable-git-update \
		--disable-gtk \
		--disable-libssh2 \
		--disable-linux-user \
		--disable-linux-aio \
		--disable-kvm \
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
		bin/qemu-system-cheri256

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cheri128-softmmu/qemu-system-cheri128 \
	    ${WRKSRC}/cheri128magic-softmmu/qemu-system-cheri128magic \
	    ${WRKSRC}/cheri256-softmmu/qemu-system-cheri256 \
	    ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
