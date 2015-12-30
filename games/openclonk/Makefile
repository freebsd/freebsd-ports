# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	openclonk
PORTVERSION=	6.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.openclonk.org/builds/release/${DISTVERSION}/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multiplayer action game involving small and nimble humanoids

LICENSE=	ISCL CC0-1.0
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libogg.so:${PORTSDIR}/audio/libogg \
		libpng.so:${PORTSDIR}/graphics/png \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

BROKEN_FreeBSD_9=	does not build (lack of proper c++11 support)

USES=		compiler:c++11-lib cmake desktop-file-utils jpeg pkgconfig tar:bzip2
USE_GL=		glew
USE_GNOME=	gtk20
USE_SDL=	sdl mixer
USE_XORG=	x11 xpm
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|DESTINATION games|DESTINATION bin|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
