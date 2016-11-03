# Created by: ijliao
# $FreeBSD$

PORTNAME=	agg
PORTVERSION=	2.5
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://distfiles.alpinelinux.org/distfiles/ \
		http://distfiles.lesslinux.org/ \
		http://gentoo.netnitco.net/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Quality Rendering Engine for C++

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/copying

LIB_DEPENDS=	libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig
USE_XORG=	x11
USE_SDL=	sdl
MAKE_ENV=	C="${CC}" AGGCXXFLAGS="${CXXFLAGS}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -I../include -L./

.include <bsd.port.mk>
