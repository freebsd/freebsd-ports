PORTNAME=	love
PORTVERSION=	11.5
PORTREVISION=	2
CATEGORIES=	devel games
MASTER_SITES=	https://github.com/love2d/love/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine
WWW=		https://www.love2d.org/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

NOT_FOR_ARCHS=		mips mips64 powerpc powerpc64 powerpcspe
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
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
WRKSRC=		${WRKDIR}/love-${PORTVERSION}
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS LUAJIT GME
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_amd64=	LUAJIT
OPTIONS_DEFAULT_powerpc64le=	LUAJIT

LUAJIT_DESC=		Use luajit
LUAJIT_USES=		luajit
LUAJIT_CONFIGURE_ON=	--with-lua=luajit
LUAJIT_USES_OFF=	lua:51  # stay compatible, e.g. games/mari0 crashes with 53..54
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
