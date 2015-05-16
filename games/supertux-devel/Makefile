# $FreeBSD$

PORTNAME=	supertux
PORTVERSION=	0.3.5
CATEGORIES=	games
MASTER_SITES=	https://github.com/SuperTux/supertux/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Side-scroller game similar to Super Mario Brothers

BUILD_DEPENDS=	${LOCALBASE}/include/boost/smart_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libphysfs.so:${PORTSDIR}/devel/physfs \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USE_SDL=	sdl2 image2
USE_GL=		glew
USES=		cmake:outsource compiler:c++11-lib iconv openal:al pkgconfig tar:bzip2
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
# Unhide std::to_string() to fix build with GCC (see ports/193528 for details)
CFLAGS+=	-D_GLIBCXX_USE_C99

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/^Icon=/s,supertux.png,supertux2.png,' \
		${WRKSRC}/supertux2.desktop

.include <bsd.port.mk>
