# New ports collection makefile for: ecl
# Date created:		  29 Januar 2004
# Whom:			Julian Stecklina
#
# $FreeBSD$
#

PORTNAME=	ecl
PORTVERSION=	0.9l
PORTREVISION=	1
CATEGORIES=	lang lisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecls
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ANSI Common Lisp implementation

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 gc.1:${PORTSDIR}/devel/boehm-gc

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-gmp --enable-boehm=system
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS=	ASDF "Enable ASDF building facility" on \
		CLOS_STREAMS "Enable user defined stream objects" on \
		CLX "Enable X11 interface" off \
		SOCKETS "Enable socket interface" on \
		THREADS "Enable threading support" off

USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/ecl

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

.if !defined(WITHOUT_CLOS_STREAMS)
CONFIGURE_ARGS+=--with-clos-streams=yes
PLIST_SUB+=	CLOS_STREAMS=""
.else
CONFIGURE_ARGS+=--with-clos-streams=no
PLIST_SUB+=	CLOS_STREAMS="@comment "
.endif

.if defined(WITH_CLX)
USE_XORG=	x11
CONFIGURE_ARGS+=--with-clx=yes
#INFO+=		clx
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
.else
CONFIGURE_ARGS+=--enable-threads=no
.endif

.if defined(WITH_THREADS)
post-patch:
	@${REINPLACE_CMD} -e 's|_NP[[:>:]]||' \
		${WRKSRC}/src/c/package.d ${WRKSRC}/src/c/threads.d
.endif

.include <bsd.port.post.mk>
