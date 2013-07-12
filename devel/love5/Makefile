# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	love
DISTVERSION=	0.5-0
PORTREVISION=	9
CATEGORIES=	devel games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine

LIB_DEPENDS=	IL:${PORTSDIR}/graphics/devil \
		physfs:${PORTSDIR}/devel/physfs \
		freetype:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

LATEST_LINK=	love5
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
USE_GL=		gl glu
USE_LUA=	5.1+
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LUA_INCDIR} `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --libdir=${PREFIX}/lib \
		--program-suffix=5
USE_DOS2UNIX=	yes

PLIST_FILES=	bin/love5

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}5
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|ILvoid|void|' ${WRKSRC}/src/opengl/Image.cpp \
		${WRKSRC}/src/opengl/love_opengl.cpp
	@${REINPLACE_CMD} -e '/^prefix=/ d; /^bindir=/ d; /^libdir=/ d' \
		${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in changes.txt readme.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
