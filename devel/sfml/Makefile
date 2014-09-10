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

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libGLEW.so:${PORTSDIR}/graphics/glew

USES=		cmake zip:infozip openal:al dos2unix
DOS2UNIX_FILES=	CMakeLists.txt
USE_XORG=	x11 xrandr
USE_GL=		gl
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

DATADIR=	${PREFIX}/share/SFML
PORTDATA=	*

OPTIONS_DEFINE=	DOXYGEN

DOXYGEN_CMAKE_ON=	-DSFML_BUILD_DOC:BOOL=YES
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

.include <bsd.port.mk>
