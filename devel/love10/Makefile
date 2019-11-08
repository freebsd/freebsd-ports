# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
PORTVERSION=	0.10.2
PORTREVISION=	2
CATEGORIES=	devel games
MASTER_SITES=	https://bitbucket.org/rude/love/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	10
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine (legacy version 0.10)

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libmodplug.so:audio/libmodplug \
		libmpg123.so:audio/mpg123 \
		libvorbisfile.so:audio/libvorbis \
		libphysfs.so:devel/physfs \
		libfreetype.so:print/freetype2 \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg

PORTSCOUT=	limit:^0\.10\.

USES=		autoreconf compiler:c++11-lib desktop-file-utils gl gmake \
		libtool localbase openal pkgconfig sdl shared-mime-info
USE_SDL=	sdl2
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/love-${PORTVERSION}
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS LUAJIT

LUAJIT_DESC=		Use luajit (broken)
LUAJIT_BROKEN=		love 0.10 segfaults when built with luajit, please disable LUAJIT option and retry
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit
LUAJIT_USES_OFF=	lua
LUAJIT_CONFIGURE_OFF=	--with-lua=lua \
			--with-luaversion="-${LUA_VER}"
LUAJIT_CONFIGURE_ENV_OFF=LUA_EXECUTABLE="${LUA_CMD}"

post-patch:
	@${REINPLACE_CMD} -e 's|\(liblove\)\(.la\)|\1${PKGNAMESUFFIX}\2|g' \
		${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -Ee \
		'/(Exec|Icon|MimeType)/ s|love|&${PKGNAMESUFFIX}|; s|LÖVE|& 0.10|; /^Comment/ s|$$| (legacy version 0.10)|' \
		${WRKSRC}/platform/unix/love.desktop.in
	@${REINPLACE_CMD} -e 's|x-love-game|x-love${PKGNAMESUFFIX}-game|; s|LÖVE|& 0.10|' \
		${WRKSRC}/platform/unix/love.xml

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/share/applications/love.desktop \
		${STAGEDIR}${PREFIX}/share/applications/love${PKGNAMESUFFIX}.desktop
	@${MV} ${STAGEDIR}${PREFIX}/share/pixmaps/love.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/love${PKGNAMESUFFIX}.svg
	@${MV} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/mimetypes/application-x-love-game.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/mimetypes/application-x-love${PKGNAMESUFFIX}-game.svg
	@${MV} ${STAGEDIR}${PREFIX}/share/mime/packages/love.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/love${PKGNAMESUFFIX}.xml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
