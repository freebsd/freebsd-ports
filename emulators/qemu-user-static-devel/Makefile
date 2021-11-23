PORTNAME=	qemu
PORTVERSION=	6.0.91
CATEGORIES=	emulators
PKGNAMESUFFIX=	-user-static-devel
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	QEMU CPU Emulator (github bsd-user branch)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=		amd64 powerpc powerpc64
CONFLICTS_INSTALL=	qemu-user-static

# When static linking we have a build dependency on libglib-2.0.a, otherwise
# we use glib20 in the usual way (shared-lib runtime dependency).
BUILD_DEPENDS=	${LOCALBASE}/lib/libglib-2.0.a:devel/glib20 \
		bash:shells/bash \
		meson>=0.57.1_1:devel/meson

USES=		bison compiler:c11 cpe gmake ninja:build perl5 pkgconfig python:build

USE_GITHUB=	yes
GH_TUPLE=	qemu-bsd-user:qemu-bsd-user:38bb64abdce3606c823ea8f9d1c7e7176fdf20c9 \
		qemu:keycodemapdb:10739aa:keycodemapdb/ui/keycodemapdb

HAS_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes

USE_PERL5=	build

USE_RC_SUBR=	qemu_user_static
SUB_LIST=	NAME=qemu_user_static

MAKE_ENV=	BSD_MAKE="${MAKE}" V=1
CONFIGURE_ARGS=	--prefix=${PREFIX} --cc=${CC} \
		--localstatedir=/var \
		--extra-ldflags=-L${LOCALBASE}/lib \
		--extra-cflags=-I${LOCALBASE}/include \
		--enable-debug \
		--enable-debug-info \
		--static \
		--python=${PYTHON_CMD} \
		--meson=${LOCALBASE}/bin/meson \
		--disable-docs --disable-tools --disable-system \
		--disable-capstone \
		--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"

TEST_TARGET=	check

.include <bsd.port.pre.mk>

QEMU_TARGETS=		i386-bsd-user arm-bsd-user mips-bsd-user mipsel-bsd-user ppc-bsd-user
.if ${ARCH} == "amd64" || ${ARCH} == "powerpc64"
QEMU_TARGETS+=		x86_64-bsd-user riscv64-bsd-user mips64-bsd-user ppc64-bsd-user aarch64-bsd-user
PLIST_SUB+=	64BIT=""
.else
PLIST_SUB+=	64BIT="@comment "
.endif
CONFIGURE_ARGS+=	--target-list=${QEMU_TARGETS:ts,}

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CFLAGS+=	-Wno-address-of-packed-member
CFLAGS+=	-D_WANT_SEMUN

QEMU_ARCH=	${ARCH:C/amd64/x86_64/:C/powerpc/ppc/}
MAKE_ARGS=	ARCH=${QEMU_ARCH}

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
	@(cd ${STAGEDIR}${PREFIX}/bin && \
		for i in qemu-*; do ${MV} -i $$i $$i-static; done)

.include <bsd.port.post.mk>
