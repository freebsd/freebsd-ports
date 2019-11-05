# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	radius-engine
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lua script-based 2D engine built on top of OpenGL and SDL

LICENSE=	MIT

LIB_DEPENDS=	liblua-5.1.so:lang/lua51 \
		libpng.so:graphics/png \
		libphysfs.so.1:devel/physfs

USES=		gl pathfix pkgconfig sdl
USE_SDL=	sdl sound
USE_GL=		glu
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	include/radius.h \
		lib/libradius-engine.a \
		libdata/pkgconfig/radius-engine.pc

post-patch:
	@${REINPLACE_CMD} -e 's|lua5.1|lua-5.1|g' \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/configure

.include <bsd.port.mk>
