# Created by: Steffen Mazanek <steffen.mazanek@unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	ohugs
PORTVERSION=	0.5
PORTREVISION=	8
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.math.chalmers.se/~nordland/ohugs/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Interpreter for Haskell with object-oriented features

OPTIONS_DEFINE=		X11

.include <bsd.port.options.mk>

LIB_DEPENDS=	libreadline.so.6:devel/readline
.if empty(PORT_OPTIONS:MX11)
LIB_DEPENDS=	libTix8.4.3.so:x11-toolkits/tix
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}
BUILD_WRKSRC=	${WRKSRC}/src
USES=		bison ncurses readline
LDFLAGS+=	-lm -lreadline -lncurses

.if ${PORT_OPTIONS:MX11}
USES+=		tk
CFLAGS+=	-I${TK_INCLUDEDIR} -I${TCL_INCLUDEDIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -ltk${TK_SHLIB_VER} -ltcl${TCL_SHLIB_VER} -lTix8.4.3
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_prelude.h
.endif

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		INSTBIN=${PREFIX}/bin INSTLIB=${PREFIX}/lib/ohugs

.include <bsd.port.mk>
