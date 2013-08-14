# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	radius-engine
PORTVERSION=	1.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lua script-based 2D engine built on top of OpenGL and SDL

LICENSE=	MIT

LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua \
		png15:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs

USES=		pathfix
USE_SDL=	sdl sound
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	include/radius.h \
		lib/libradius-engine.a \
		libdata/pkgconfig/radius-engine.pc
PLIST_DIRSTRY=	libdata/pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's|lua5.1|lua-5.1|g' \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/configure

.include <bsd.port.mk>
