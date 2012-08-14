# New ports collection makefile for: ecl
# Date created:		  29 Januar 2004
# Whom:			Julian Stecklina
#
# $FreeBSD$
#

PORTNAME=	ecl
PORTVERSION=	12.7.1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}s/${PORTNAME}s/12.7/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An ANSI Common Lisp implementation

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
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

MAN1=		ecl.1 ecl-config.1

PLIST_SUB=      VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

.if ${PORT_OPTIONS:MASDF}
CONFIGURE_ARGS+=--with-asdf=yes
PLIST_SUB+=	ASDF=""
.else
CONFIGURE_ARGS+=--with-asdf=no
PLIST_SUB+=	ASDF="@comment "
.endif

.if ${PORT_OPTIONS:MCLX}
USE_XORG=	x11
CONFIGURE_ARGS+=--with-clx=yes
PLIST_SUB+=	CLX=""
.else
CONFIGURE_ARGS+=--with-clx=no
PLIST_SUB+=	CLX="@comment "
.endif

.if ${PORT_OPTIONS:MSOCKETS}
CONFIGURE_ARGS+=--with-tcp=yes
PLIST_SUB+=	SOCKETS=""
.else
CONFIGURE_ARGS+=--with-tcp=no
PLIST_SUB+=	SOCKETS="@comment "
.endif

.if ${PORT_OPTIONS:MDFFI}
CONFIGURE_ARGS+=--with-dffi=system
LIB_DEPENDS+=	ffi:${PORTSDIR}/devel/libffi
.else
CONFIGURE_ARGS+=--with-dffi=no
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads=yes
LDFLAGS+=	${PTHREAD_LIBS}
LIB_DEPENDS+=	gc-threaded:${PORTSDIR}/devel/boehm-gc-threaded
PLIST_SUB+=	THREADS=""
.else
CONFIGURE_ARGS+=--enable-threads=no
LIB_DEPENDS+=	gc:${PORTSDIR}/devel/boehm-gc
PLIST_SUB+=	THREADS="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
post-patch:
	@${REINPLACE_CMD} -e 's|-lgc|-lgc-threaded|' \
 		-e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/src/configure
.endif

.include <bsd.port.post.mk>
