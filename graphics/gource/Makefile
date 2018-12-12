# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	gource
PORTVERSION=	0.47
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/acaudwell/Gource/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	OpenGL-based 3D visualisation tool for source control repositories

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libSDL_image.so:graphics/sdl_image \
		libfreetype.so:print/freetype2 \
		libpcre.so:devel/pcre \
		libboost_filesystem.so:devel/boost-libs \
		libpng.so:graphics/png
RUN_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig compiler:c++0x
USE_GL=		glew gl glu
USE_SDL=	image2 sdl2

CONFIGURE_ARGS+=--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
