# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	allacrost
PORTVERSION=	1.0.2
PORTREVISION=	14
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
USES=		gettext gmake iconv jpeg lua:51 openal:al
USE_SDL=	sdl ttf net
USE_GL=		yes
USE_GCC=	any # problems in luabind
QT_NONSTANDARD=	yes # used when EDITOR enabled

CONFIGURE_ARGS=	--datadir=${DATADIR}
CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	EDITOR DOCS
OPTIONS_SUB=	yes

EDITOR_DESC=		Enable editor

EDITOR_USE=		QT4=corelib,gui,moc_build,opengl,qt3support
EDITOR_CONFIGURE_ON=	--enable-editor=yes
EDITOR_CONFIGURE_OFF=	--enable-editor=no

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

post-patch-EDITOR-on:
	@${REINPLACE_CMD} -e '/^INCLUDES = / s|=|= -I${QT_INCDIR}/QtGui \
		-I${QT_INCDIR}/QtOpenGL -I${QT_INCDIR}/Qt3Support \
		-I${QT_INCDIR}/QtCore -I${QT_INCDIR}|' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
