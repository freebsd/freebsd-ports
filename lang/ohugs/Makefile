# Created by: Steffen Mazanek <steffen.mazanek@unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	ohugs
PORTVERSION=	0.5
PORTREVISION=	10
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.math.chalmers.se/~nordland/ohugs/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Interpreter for Haskell with object-oriented features

BROKEN=		unfetchable

OPTIONS_DEFINE=		X11

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}
BUILD_WRKSRC=	${WRKSRC}/src
USES=		bison ncurses readline:port
LDFLAGS+=	-lm -lreadline -lncurses

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		INSTBIN=${PREFIX}/bin INSTLIB=${PREFIX}/lib/ohugs

X11_CFLAGS=		-I${TK_INCLUDEDIR} -I${TCL_INCLUDEDIR} -I${LOCALBASE}/include
X11_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-src_prelude.h
X11_LDFLAGS=		-L${LOCALBASE}/lib -ltk${TK_SHLIB_VER} -ltcl${TCL_SHLIB_VER} -lTix8.4.3
X11_LIB_DEPENDS_OFF=	libTix8.4.3.so:x11-toolkits/tix
X11_USES=		tk

.include <bsd.port.mk>
