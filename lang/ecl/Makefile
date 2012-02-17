# New ports collection makefile for: ecl
# Date created:		  29 Januar 2004
# Whom:			Julian Stecklina
#
# $FreeBSD$
#

PORTNAME=	ecl
PORTVERSION=	12.2.1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}s/${PORTNAME}s/12.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An ANSI Common Lisp implementation

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-gmp --enable-boehm=system
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS=	ASDF "Enable ASDF building facility" on \
		CLX "Enable X11 interface" off \
		SOCKETS "Enable socket interface" on \
		THREADS "Enable threading support" off

MAN1=		ecl.1 ecl-config.1

PLIST_SUB=      VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

.if !defined(WITHOUT_ASDF)
CONFIGURE_ARGS+=--with-asdf=yes
PLIST_SUB+=	ASDF=""
.else
CONFIGURE_ARGS+=--with-asdf=no
PLIST_SUB+=	ASDF="@comment "
.endif

.if defined(WITH_CLX)
USE_XORG=	x11
CONFIGURE_ARGS+=--with-clx=yes
PLIST_SUB+=	CLX=""
.else
CONFIGURE_ARGS+=--with-clx=no
PLIST_SUB+=	CLX="@comment "
.endif

.if !defined(WITHOUT_SOCKETS)
CONFIGURE_ARGS+=--with-tcp=yes
PLIST_SUB+=	SOCKETS=""
.else
CONFIGURE_ARGS+=--with-tcp=no
PLIST_SUB+=	SOCKETS="@comment "
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=--enable-threads=yes
LDFLAGS+=	${PTHREAD_LIBS}
LIB_DEPENDS+=	gc-threaded.1:${PORTSDIR}/devel/boehm-gc-threaded
.else
CONFIGURE_ARGS+=--enable-threads=no
LIB_DEPENDS+=	gc.1:${PORTSDIR}/devel/boehm-gc
.endif

.if defined(WITH_THREADS)
post-patch:
	@${REINPLACE_CMD} -e 's|-lgc|-lgc-threaded|' \
 		-e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/src/configure
.endif

.include <bsd.port.post.mk>
