# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	openclonk
PORTVERSION=	6.0
DISTVERSIONSUFFIX=	-src
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

USES=		compiler:c++11-lib cmake desktop-file-utils iconv jpeg pkgconfig tar:bzip2
USE_GL=		glew
USE_GNOME=	gtk20
USE_SDL=	sdl mixer
USE_XORG=	x11 xpm
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/openclonk-release-${DISTVERSION}-src

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
BROKEN=		does not build (lack of proper c++11 support)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|DESTINATION games|DESTINATION bin|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
