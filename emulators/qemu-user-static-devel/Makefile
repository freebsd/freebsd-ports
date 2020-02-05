# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	emulators
PKGNAMESUFFIX=	-user-static-devel
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	QEMU CPU Emulator (github bsd-user branch)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=		amd64 powerpc powerpc64
CONFLICTS_INSTALL=	qemu-user-static-[0-9]*

USES=		bison compiler:c11 gmake perl5 pkgconfig python:build
USE_GITHUB=	yes
GH_TUPLE=	seanbruno:qemu-bsd-user:e21442a	\
		qemu:keycodemapdb:10739aa:keycodemapdb/ui/keycodemapdb
HAS_CONFIGURE=	yes
USE_PERL5=	build
MAKE_ENV+=	BSD_MAKE="${MAKE}" V=1

USE_RC_SUBR=	qemu_user_static
SUB_LIST=	NAME=qemu_user_static

# When static linking we have a build dependency on libglib-2.0.a, otherwise
# we use glib20 in the usual way (shared-lib runtime dependency).
BUILD_DEPENDS+=	${LOCALBASE}/lib/libglib-2.0.a:devel/glib20

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--extra-ldflags=-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--extra-cflags=-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--disable-libssh2

QEMU_TARGETS=		i386-bsd-user sparc-bsd-user arm-bsd-user mips-bsd-user mipsel-bsd-user ppc-bsd-user
.if ${ARCH} == "amd64" || ${ARCH} == "powerpc64"
QEMU_TARGETS+=		x86_64-bsd-user riscv64-bsd-user sparc64-bsd-user mips64-bsd-user mips64el-bsd-user ppc64-bsd-user aarch64-bsd-user
PLIST_SUB+=	64BIT=""
.else
PLIST_SUB+=	64BIT="@comment "
.endif
CONFIGURE_ARGS+=	--target-list=${QEMU_TARGETS:ts,}

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CFLAGS+=	-Wno-address-of-packed-member
CFLAGS+=	-D_WANT_SEMUN
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC} --enable-docs \
	--disable-linux-user --disable-linux-aio \
	--disable-kvm --disable-xen \
	--smbd=${LOCALBASE}/sbin/smbd \
	--enable-debug \
	--enable-debug-info \
	--static \
	--python=${PYTHON_CMD} \
	--disable-sdl --disable-gtk --disable-vte --disable-gnutls --disable-vnc \
	--disable-curl --disable-opengl --disable-usb-redir --disable-pcap \
	--disable-docs --disable-tools --disable-system --disable-guest-agent \
	--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"\"${PREFIX}\\\"\"

QEMU_ARCH=	${ARCH:C/amd64/x86_64/:C/powerpc/ppc/}
MAKE_ARGS+=	ARCH=${QEMU_ARCH}

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s|^(CFLAGS=).*|\1${CFLAGS} -fno-strict-aliasing|" \
		-e "s|^(LDFLAGS=).*|\1${LDFLAGS}|" \
		${WRKSRC}/Makefile.target
	@${REINPLACE_CMD} -E \
		-e "s|^(CFLAGS=).*|\1${CFLAGS} -fno-strict-aliasing -I.|" \
		-e "s|^(LDFLAGS=).*|\1${LDFLAGS}|" \
		${WRKSRC}/Makefile

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/rc.d ${WRKDIR}
	@${RM} -r ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	@${MV} ${WRKDIR}/rc.d ${STAGEDIR}${PREFIX}/etc
	@${RM} -r ${STAGEDIR}${PREFIX}/man
	@${RM} -r ${STAGEDIR}${DATADIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
	@(cd ${STAGEDIR}${PREFIX}/bin && \
		for i in qemu-*; do ${MV} -i $$i $$i-static; done)

.include <bsd.port.post.mk>
