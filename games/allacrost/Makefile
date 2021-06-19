PORTNAME=	allacrost
PORTVERSION=	1.0.2
PORTREVISION=	30
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-demo/${PORTVERSION}
DISTNAME=	${PORTNAME}_demo_source_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single player 2D role-playing game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libboost_thread.so:devel/boost-libs

GNU_CONFIGURE=	yes
USES=		gettext gl gmake iconv jpeg localbase lua:51 openal:al sdl xorg
USE_SDL=	sdl ttf net
USE_GL=		gl glu
USE_XORG=	x11
USE_CXXSTD=	c++98

CONFIGURE_ARGS=	--datadir=${DATADIR} --enable-editor=no
CPPFLAGS+=	-isystem${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
LDFLAGS_i386=	-Wl,-znotext

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include/|-I${LOCALBASE}/include/|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|exit -1|exit 1|; /CXXFLAGS=/ d; \
		s|-lSDL |`${SDL_CONFIG} --libs` |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^LIBS =/ s|$$| @INTLLIBS@|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^bindir = / s|games|bin|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/qt4_incdirs/ s|".*"|"${QT_INCDIR}"|; \
		/qt4_libdirs/ s|".*"|"${QT_LIBDIR}"|; /test/ s|==|=| ; \
		s/-llua /-llua-${LUA_VER} /g;' \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
