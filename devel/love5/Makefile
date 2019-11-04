# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
DISTVERSION=	0.5-0
PORTREVISION=	28
CATEGORIES=	devel games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMESUFFIX=	5

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LIB_DEPENDS=	libIL.so:graphics/devil \
		libphysfs.so:devel/physfs \
		libfreetype.so:print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

USES=		tar:bzip2 gmake gl dos2unix lua:51 sdl
USE_SDL=	sdl mixer
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LUA_INCDIR} `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --libdir=${PREFIX}/lib \
		--program-suffix=5
DOS2UNIX_FILES=	src/system/love_system.cpp

PLIST_FILES=	bin/love5

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}5
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|ILvoid|void|' ${WRKSRC}/src/opengl/Image.cpp \
		${WRKSRC}/src/opengl/love_opengl.cpp
	@${REINPLACE_CMD} -e '/^prefix=/ d; /^bindir=/ d; /^libdir=/ d' \
		-e "s/lua5.1/lua-${LUA_VER}/g" \
		${WRKSRC}/configure

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
