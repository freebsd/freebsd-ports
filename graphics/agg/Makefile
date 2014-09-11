# Created by: ijliao
# $FreeBSD$

PORTNAME=	agg
PORTVERSION=	2.5
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.antigrain.com/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Quality Rendering Engine for C++

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USE_XORG=	x11
USES=		gmake libtool pathfix pkgconfig
USE_SDL=	sdl
USE_AUTOTOOLS=	aclocal autoheader autoconf libtoolize automake
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--foreign --add-missing --ignore-deps
MAKE_ENV=	C="${CC}" AGGCXXFLAGS="${CXXFLAGS}"
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -I../include -L./

BROKEN_sparc64=		Does not compile

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.am

.include <bsd.port.mk>
