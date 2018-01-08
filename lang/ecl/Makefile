# Created by: Julian Stecklina
# $FreeBSD$

PORTNAME=	ecl
PORTVERSION=	15.3.7
PORTREVISION=	2
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}s/${PORTNAME}s/15.3/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ANSI Common Lisp implementation

LICENSE=	LGPL20

LIB_DEPENDS=	libgmp.so:math/gmp

BROKEN_aarch64=		Does not compile: error: unknown type name AO_TS_t
BROKEN_powerpc64=	Does not link: undefined reference to fmodl

MAKE_JOBS_UNSAFE=	yes
USES=		gmake perl5 tar:tgz
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-gmp --with-gmp-prefix=${LOCALBASE} --enable-boehm=system
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ASDF CLX DFFI SOCKETS THREADS
OPTIONS_DEFAULT=ASDF DFFI SOCKETS THREADS

ASDF_DESC=	Enable ASDF building facility
CLX_DESC=	Enable X11 interface
SOCKETS_DESC=	Enable socket interface
DFFI_DESC=	Dynamic foreign-function support

OPTIONS_SUB=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

ASDF_CONFIGURE_ON=	--with-asdf=yes
ASDF_CONFIGURE_OFF=	--with-asdf=no

CLX_USE=		XORG=x11
CLX_CONFIGURE_ON=	--with-clx=yes
CLX_CONFIGURE_OFF=	--with-clx=no

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

.include <bsd.port.mk>
