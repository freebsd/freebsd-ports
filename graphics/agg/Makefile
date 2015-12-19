# Created by: ijliao
# $FreeBSD$

PORTNAME=	agg
PORTVERSION=	2.5
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://www.antigrain.com/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Quality Rendering Engine for C++

BROKEN=		unfetchable
LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/copying

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig
USE_XORG=	x11
USE_SDL=	sdl
MAKE_ENV=	C="${CC}" AGGCXXFLAGS="${CXXFLAGS}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -I../include -L./

BROKEN_sparc64=		Does not compile

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
