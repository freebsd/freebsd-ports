# Created by: Julian Stecklina
# $FreeBSD$

PORTNAME=	ecl
PORTVERSION=	15.3.7
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}s/${PORTNAME}s/15.3/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ANSI Common Lisp implementation

LICENSE=	LGPL20

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

.if ${PORT_OPTIONS:MASDF}
CONFIGURE_ARGS+=--with-asdf=yes
.else
CONFIGURE_ARGS+=--with-asdf=no
.endif

.if ${PORT_OPTIONS:MCLX}
USE_XORG=	x11
CONFIGURE_ARGS+=--with-clx=yes
.else
CONFIGURE_ARGS+=--with-clx=no
.endif

.if ${PORT_OPTIONS:MSOCKETS}
CONFIGURE_ARGS+=--with-tcp=yes
.else
CONFIGURE_ARGS+=--with-tcp=no
.endif

.if ${PORT_OPTIONS:MDFFI}
CONFIGURE_ARGS+=--with-dffi=system
LIB_DEPENDS+=	libffi.so:${PORTSDIR}/devel/libffi
.else
CONFIGURE_ARGS+=--with-dffi=no
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads=yes
LDFLAGS+=	-lpthread
LIB_DEPENDS+=	libgc-threaded.so:${PORTSDIR}/devel/boehm-gc-threaded
.else
CONFIGURE_ARGS+=--enable-threads=no
LIB_DEPENDS+=	libgc.so:${PORTSDIR}/devel/boehm-gc
.endif

.if ${PORT_OPTIONS:MTHREADS}
post-patch:
	@${REINPLACE_CMD} -e 's|-lgc|-lgc-threaded|' ${WRKSRC}/src/configure
.endif

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/include/ecl/gc/private

.include <bsd.port.post.mk>
