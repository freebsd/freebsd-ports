# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
PORTVERSION=	0.7.2
PORTREVISION=	23
CATEGORIES=	devel games
MASTER_SITES=	http://cdn.bitbucket.org/rude/love/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	07
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LIB_DEPENDS=	libIL.so:graphics/devil \
		libmodplug.so:audio/libmodplug \
		libmpg123.so:audio/mpg123 \
		libvorbisfile.so:audio/libvorbis \
		libphysfs.so:devel/physfs \
		libfreetype.so:print/freetype2 \
		libtiff.so:graphics/tiff \
		libmng.so:graphics/libmng
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

PORTSCOUT=	limit:^0\.7\.

USES=		compiler:c++11-lang gmake gl openal dos2unix lua:51 sdl
USE_SDL=	sdl mixer
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LUA_INCDIR} `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
LDFLAGS_i386=	-Wl,-znotext
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --libdir=${PREFIX}/lib \
		--program-suffix=07
WRKSRC=		${WRKDIR}/love-HEAD
DOS2UNIX_FILES=	src/modules/graphics/opengl/GLee.h

PLIST_FILES=	bin/love07

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}07
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^prefix=/ d; /^bindir=/ d; /^libdir=/ d' \
		-e "s/lua5.1/lua-${LUA_VER}/g" \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
