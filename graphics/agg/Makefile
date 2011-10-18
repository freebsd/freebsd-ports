# Ports collection makefile for:	agg
# Date created:			Aug 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	agg
PORTVERSION=	2.5
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.antigrain.com/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A High Quality Rendering Engine for C++

LICENSE=	GPLv2

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_XORG=	x11
USE_GNOME=	gnomehack pkgconfig
USE_SDL=	sdl
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal autoheader autoconf libtoolize automake
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--foreign --add-missing --ignore-deps
MAKE_ENV=	C="${CC}" AGGCXXFLAGS="${CXXFLAGS}"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -I../include -L./

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
