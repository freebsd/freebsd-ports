# Ports collection makefile for:	agg
# Date created:			Aug 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	agg
PORTVERSION=	2.5
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.antigrain.com/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A High Quality Rendering Engine for C++

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_XORG=	x11
USE_GNOME=	pkgconfig gnomehack
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal
USE_AUTOTOOLS=	autoconf:262:env automake:15:env libtool:22:env
MAKE_ENV=	C="${CC}" AGGCXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -I../include -L./

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ACLOCAL_ARGS="${ACLOCAL_ARGS}" ${SH} autogen.sh

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
