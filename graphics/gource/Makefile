# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	gource
PORTVERSION=	0.40
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	OpenGL-based 3D visualisation tool for source control repositories

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:${PORTSDIR}/math/glm
LIB_DEPENDS=	libSDL_image.so:${PORTSDIR}/graphics/sdl_image \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:${PORTSDIR}/math/glm

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GCC=	yes

CONFIGURE_ARGS+=--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
