PORTNAME=	qemu
PORTVERSION=	0.d${SNAPDATE}
CATEGORIES=	emulators devel
PKGNAMESUFFIX=	-cheri

MAINTAINER=	brooks@FreeBSD.org
COMMENT?=	QEMU emulator with CHERI CPU support
WWW=		https://github.com/CTSRD-CHERI/qemu

# XXX: disabling gnutls doesn't work so depend on it to avoid breakage.
BUILD_DEPENDS=	bash:shells/bash \
		meson>=0.57.1_1:devel/meson
LIB_DEPENDS=	libcapstone.so:devel/capstone3 \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libgnutls.so:security/gnutls \
		libnettle.so:security/nettle
RUN_DEPENDS=	qemu-system-i386:emulators/qemu

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_TUPLE=	CTSRD-CHERI:qemu:${QEMU_COMMIT} \
		qemu:dtc:85e5d83:qemu_dtc/dtc \
		qemu:libslirp:487f4bf4:qemu_libslirp/slirp \
		qemu:berkeley-softfloat-3:b64af41:qemu_berkeley_softfloat_3/tests/fp/berkeley-softfloat-3 \
		qemu:berkeley-testfloat-3:ca9fa2b:qemu_berkeley_testfloat_3/tests/fp/berkeley-testfloat-3 \
		qemu:keycodemapdb:6b3d716:qemu_keycodemapdb/ui/keycodemapdb \

HAS_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
USES=		cpe gmake gnome ninja:build perl5 pkgconfig python:build xorg
USE_XORG=	pixman
USE_GNOME+=	glib20 libxml2
USE_PERL5=	build
USE_GL+=	gl
ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

OPTIONS_DEFINE=	DOCS

.include "Makefile.snapshot"

CONFIGURE_ARGS+= \
		--target-list=riscv64cheri-softmmu,morello-softmmu \
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
		--meson=${LOCALBASE}/bin/meson \
		--smbd=${LOCALBASE}/sbin/smbd \
		--extra-cflags="-g ${EXTRA_CFLAGS}" \
		--localstatedir=/var
EXTRA_CFLAGS=	-DCHERI_UNALIGNED

PLIST_FILES=	bin/qemu-system-morello \
		bin/qemu-system-riscv64cheri

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/qemu-system-morello \
	    ${WRKSRC}/build/qemu-system-riscv64cheri \
	    ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
