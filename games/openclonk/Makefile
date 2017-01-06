# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	openclonk
PORTVERSION=	7.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.openclonk.org/builds/release/${DISTVERSION}/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multiplayer action game involving small and nimble humanoids

LICENSE=	ISCL CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++14-lang cmake desktop-file-utils jpeg pkgconfig tar:bzip2
USE_GL=		glew
USE_GNOME=	gtk30
USE_SDL=	sdl mixer
USE_XORG=	x11 xpm
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|DESTINATION games|DESTINATION bin|' \
		-e 's|share/games|share|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
