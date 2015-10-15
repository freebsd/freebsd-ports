# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	devel games
MASTER_SITES=	https://bitbucket.org/rude/love/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libIL.so:${PORTSDIR}/graphics/devil \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		libmpg123.so:${PORTSDIR}/audio/mpg123 \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libphysfs.so:${PORTSDIR}/devel/physfs \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=           gmake openal libtool pkgconfig compiler:c++11-lib \
		desktop-file-utils shared-mime-info
USE_SDL=	sdl2
USE_GL=		gl glu
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/love-${PORTVERSION}
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LUAJIT
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_amd64=	LUAJIT

LUAJIT_DESC=	Use luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit
LUAJIT_USES_OFF=	lua
LUAJIT_CONFIGURE_OFF=	--with-lua=lua \
			--with-luaversion="${LUA_VER}"
LUAJIT_CONFIGURE_ENV_OFF=LUA_EXECUTABLE="${LUA_CMD}"

post-patch-LUAJIT-off:
	@${REINPLACE_CMD} -e 's|$${with_lua}$${with_luaversion}|$${with_lua}-$${with_luaversion}|g' \
		${WRKSRC}/configure

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
