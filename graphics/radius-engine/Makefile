# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	radius-engine
PORTVERSION=	1.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Lua script-based 2D engine built on top of OpenGL and SDL

LICENSE=	MIT

LIB_DEPENDS=	liblua-5.1.so:${PORTSDIR}/lang/lua \
		libpng15.so:${PORTSDIR}/graphics/png \
		libphysfs.so.1:${PORTSDIR}/devel/physfs

USES=		pathfix pkgconfig
USE_SDL=	sdl sound
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	include/radius.h \
		lib/libradius-engine.a \
		libdata/pkgconfig/radius-engine.pc

post-patch:
	@${REINPLACE_CMD} -e 's|lua5.1|lua-5.1|g' \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/configure

.include <bsd.port.mk>
