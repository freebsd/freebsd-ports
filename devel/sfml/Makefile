# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sfml
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.sfml-dev.org/download/sfml/${PORTVERSION}/
DISTNAME=	SFML-${PORTVERSION}-sources

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple and Fast Multimedia Library

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libfreetype.so:print/freetype2

USES=		cmake dos2unix jpeg openal:al zip:infozip
DOS2UNIX_FILES=	CMakeLists.txt
USE_XORG=	x11 xrandr
USE_GL=		gl glew
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

DATADIR=	${PREFIX}/share/SFML
PORTDATA=	*

OPTIONS_DEFINE=	DOXYGEN

DOXYGEN_CMAKE_ON=	-DSFML_BUILD_DOC:BOOL=YES
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

.include <bsd.port.mk>
