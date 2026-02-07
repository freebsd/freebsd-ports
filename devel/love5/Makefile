PORTNAME=	love
DISTVERSION=	0.5-0
PORTREVISION=	31
CATEGORIES=	devel games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMESUFFIX=	5

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine
WWW=		https://www.love2d.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libIL.so:graphics/devil \
		libphysfs.so:devel/physfs

USES=		dos2unix gl gmake localbase:ldflags lua:51 sdl tar:bzip2
DOS2UNIX_FILES=	src/system/love_system.cpp
USE_CXXSTD=	c++14
USE_GL=		gl glu
USE_SDL=	mixer sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin \
		--libdir=${PREFIX}/lib \
		--program-suffix=5

CPPFLAGS+=	-I${LOCALBASE}/include/freetype2 \
		-I${LUA_INCDIR} `${SDL_CONFIG} --cflags`
CXXFLAGS+=	-fsigned-char
LDFLAGS+=	-L${LUA_LIBDIR}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

PLIST_FILES=	bin/love5
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|ILvoid|void|' ${WRKSRC}/src/opengl/Image.cpp \
		${WRKSRC}/src/opengl/love_opengl.cpp
	@${REINPLACE_CMD} -e '/^prefix=/ d; /^bindir=/ d; /^libdir=/ d' \
		-e "s/lua5.1/lua-${LUA_VER}/g" \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
