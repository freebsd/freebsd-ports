# Created by: Julian Stecklina
# $FreeBSD$

PORTNAME=	ecl
PORTVERSION=	16.1.3
CATEGORIES=	lang lisp
MASTER_SITES=	https://common-lisp.net/project/ecl/static/files/release/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ANSI Common Lisp implementation

LICENSE=	LGPL20

BROKEN_aarch64=		fails to compile: error: unknown type name AO_TS_t
BROKEN_mips=		fails to build: qemu: uncaught target signal 11 (Segmentation fault) - core dumped
BROKEN_mips64=		fails to build: qemu: uncaught target signal 11 (Segmentation fault) - core dumped

LIB_DEPENDS=	libgmp.so:math/gmp

MAKE_JOBS_UNSAFE=	yes
USES=		gmake perl5 tar:tgz
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-gmp --with-gmp-prefix=${LOCALBASE} --enable-boehm=system
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ASDF DFFI SOCKETS THREADS X11
OPTIONS_DEFAULT=ASDF DFFI SOCKETS THREADS

ASDF_DESC=	Enable ASDF building facility
SOCKETS_DESC=	Enable socket interface
DFFI_DESC=	Dynamic foreign-function support

OPTIONS_SUB=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

ASDF_CONFIGURE_ON=	--with-asdf=yes
ASDF_CONFIGURE_OFF=	--with-asdf=no

X11_USES=		xorg
X11_USE=		XORG=x11
X11_CONFIGURE_ON=	--with-x=yes
X11_CONFIGURE_OFF=	--with-x=no

SOCKETS_CONFIGURE_ON=	--with-tcp=yes
SOCKETS_CONFIGURE_OFF=	--with-tcp=no

DFFI_LIB_DEPENDS=	libffi.so:devel/libffi
DFFI_CONFIGURE_ON=	--with-dffi=system
DFFI_CONFIGURE_OFF=	--with-dffi=no

THREADS_CONFIGURE_ON=	--enable-threads=yes
THREADS_LDFLAGS=	-lpthread
THREADS_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
THREADS_CONFIGURE_OFF=	--enable-threads=no
THREADS_LIB_DEPENDS_OFF=	libgc.so:devel/boehm-gc

post-patch-THREADS-on:
	@${REINPLACE_CMD} -e 's|-lgc|-lgc-threaded|' ${WRKSRC}/src/configure

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/include/ecl/gc/private
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libecl.so.${PORTVERSION}

.include <bsd.port.mk>
