# New Ports collection makefile for:	Radius Engine
# Date created:		2012-05-17
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	radius-engine
PORTVERSION=	1.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Lua script-based 2D engine built on top of OpenGL and SDL

LICENSE=	MIT

LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua \
		png:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${LOCALBASE}/include
USE_SDL=	sdl sound
USE_GL=		glu
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	include/radius.h \
		lib/libradius-engine.a \
		libdata/pkgconfig/radius-engine.pc
PLIST_DIRSTRY=	libdata/pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's|lua5.1|lua-5.1|g' \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(pkgconfigdir)|{PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
