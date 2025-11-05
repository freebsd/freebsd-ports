PORTNAME=	lincity-ng
DISTVERSION=	2.14.2
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Improved rich city simulation game for X
WWW=		https://github.com/lincity-ng/lincity-ng/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libxml++-5.0.so:textproc/libxml++

USES=		cmake:noninja compiler:c++17-lang gl gnome localbase:ldflags \
		pkgconfig sdl tar:xz xorg
USE_GL=		gl
USE_GNOME=	libxml2 libxslt
USE_SDL=	image2 mixer2 sdl2 ttf2
USE_XORG=	x11

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man/man6

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
