# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	gource
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/acaudwell/Gource/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	OpenGL-based 3D visualisation tool for source control repositories

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:${PORTSDIR}/math/glm
LIB_DEPENDS=	libSDL_image.so:${PORTSDIR}/graphics/sdl_image \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:${PORTSDIR}/math/glm

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig compiler:c++0x
USE_GL=		glew

CONFIGURE_ARGS+=--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
