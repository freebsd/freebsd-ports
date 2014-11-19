# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	openclonk
PORTVERSION=	5.1
DISTVERSIONPREFIX=	5.
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://www.openclonk.org/builds/release/${DISTVERSIONPREFIX}${DISTVERSION}/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multiplayer action game involving small and nimble humanoids

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libogg.so:${PORTSDIR}/audio/libogg \
		libpng.so:${PORTSDIR}/graphics/png \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USES=		cmake iconv pkgconfig tar:bzip2
USE_GL=		glew
USE_GNOME=	gtk20
USE_SDL=	sdl mixer
USE_XORG=	x11 xpm

WRKSRC=		${WRKDIR}/openclonk-release-${DISTVERSIONPREFIX}${DISTVERSION}-src

post-patch:
	@${REINPLACE_CMD} -e 's|DESTINATION games|DESTINATION bin|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
