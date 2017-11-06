# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sfml
PORTVERSION=	2.4.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.sfml-dev.org/download/sfml/${PORTVERSION}/
DISTNAME=	SFML-${PORTVERSION}-sources

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple and Fast Multimedia Library

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libfreetype.so:print/freetype2 \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libxcb-image.so:x11/xcb-util-image

USES=		cmake compiler:c++11-lang dos2unix jpeg openal:al zip:infozip
CMAKE_ARGS=	-DSFML_INSTALL_PKGCONFIG_FILES=ON
DOS2UNIX_FILES=	CMakeLists.txt
USE_XORG=	x11 xext xrandr
USE_GL=		gl
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

DATADIR=	${PREFIX}/share/SFML
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES DOXYGEN

DOXYGEN_CMAKE_BOOL=	SFML_BUILD_DOC
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

EXAMPLES_CMAKE_BOOL=	SFML_BUILD_EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog.txt ${WRKSRC}/readme.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
