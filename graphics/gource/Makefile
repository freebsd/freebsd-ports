# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	gource
PORTVERSION=	0.40
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	OpenGL-based 3D visualisation tool for source control repositories

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:${PORTSDIR}/math/glm
LIB_DEPENDS=	SDL_image:${PORTSDIR}/graphics/sdl_image \
		freetype:${PORTSDIR}/print/freetype2 \
		pcre:${PORTSDIR}/devel/pcre \
		GLEW:${PORTSDIR}/graphics/glew \
		boost_filesystem:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:${PORTSDIR}/math/glm

GNU_CONFIGURE=	yes
USE_GCC=	yes
USE_GMAKE=	yes
MANCOMPRESSED=	yes

CONFIGURE_ARGS+=--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gource.1

.include <bsd.port.mk>
