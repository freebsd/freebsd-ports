# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	gource
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/acaudwell/Gource/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	OpenGL-based 3D visualisation tool for source control repositories

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpcre.so:devel/pcre \
		libboost_filesystem.so:devel/boost-libs \
		libpng.so:graphics/png
RUN_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		compiler:c++0x gl gmake pkgconfig sdl
GNU_CONFIGURE=	yes
USE_GL=		glew gl glu
USE_SDL=	image2 sdl2

.include <bsd.port.mk>
