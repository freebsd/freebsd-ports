# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	2.10.0
CATEGORIES=	emulators
MASTER_SITES=	GH \
		LOCAL/nox:dtc \
		http://people.freebsd.org/~nox/tmp/distfiles/:dtc
PKGNAMESUFFIX?=	-ppcnv
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		dtc-v1.4.0${EXTRACT_SUFX}:dtc

MAINTAINER=	linimon@FreeBSD.org
COMMENT=	Fork of QEMU with experimental PowerPCNV emulation support

LICENSE=	GPLv2

IGNORE_FreeBSD_10=	does not build

BUILD_DEPENDS+=		${LOCALBASE}/lib/libfdt.so:sysutils/dtc

USE_GITHUB=	yes
GH_ACCOUNT=	dgibson
GH_PROJECT=	qemu
GH_TAGNAME=	8d5981c

HAS_CONFIGURE=	yes
USES=		gmake libtool makeinfo pkgconfig python:2,build
USE_XORG=	pixman
USE_GNOME+=	glib20
ONLY_FOR_ARCHS=	amd64

CONFIGURE_ARGS+=--target-list=ppc-softmmu,ppcemb-softmmu,ppc64-softmmu \
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

PLIST_FILES=	bin/qemu-system-ppcnv \
		bin/qemu-system-ppc64nv \
		bin/qemu-system-ppcembnv

# XXX this magic should not be necessary, but seems to be:
post-patch:
	@${MV} ${WRKDIR}/dtc ${WRKSRC}

# remap names to avoid conflicts with mainline port
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppc-softmmu/qemu-system-ppc ${STAGEDIR}${PREFIX}/bin/qemu-system-ppcnv
	${INSTALL_PROGRAM} ${WRKSRC}/ppc64-softmmu/qemu-system-ppc64 ${STAGEDIR}${PREFIX}/bin/qemu-system-ppc64nv
	${INSTALL_PROGRAM} ${WRKSRC}/ppcemb-softmmu/qemu-system-ppcemb ${STAGEDIR}${PREFIX}/bin/qemu-system-ppcembnv

.include <bsd.port.mk>
