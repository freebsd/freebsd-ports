# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
PORTVERSION=	11.3
CATEGORIES=	devel games
MASTER_SITES=	https://bitbucket.org/rude/love/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe sparc64
NOT_FOR_ARCHS_REASON=	Hashing not yet implemented for big endian

LIB_DEPENDS=	libmodplug.so:audio/libmodplug \
		libmpg123.so:audio/mpg123 \
		libvorbisfile.so:audio/libvorbis \
		libfreetype.so:print/freetype2 \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg

USES=		autoreconf compiler:c++11-lib desktop-file-utils gl gmake \
		libtool localbase openal pkgconfig sdl shared-mime-info
USE_SDL=	sdl2
USE_GL=		gl glu
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/love-${PORTVERSION}
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS LUAJIT GME
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_amd64=	LUAJIT

LUAJIT_DESC=		Use luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit
# does not build with newer lua versions:
# love.cpp:217:9: error: no matching function for call to 'lua_resume'
LUAJIT_USES_OFF=	lua:51
LUAJIT_CONFIGURE_OFF=	--with-lua=lua \
			--with-luaversion="-${LUA_VER}"
LUAJIT_CONFIGURE_ENV_OFF=LUA_EXECUTABLE="${LUA_CMD}"

GME_DESC=		Enable GME support, for more chiptuney goodness
GME_CONFIGURE_ENABLE=	gme
GME_LIB_DEPENDS=	libgme.so:audio/libgme

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/platform/unix/deps.m4

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
