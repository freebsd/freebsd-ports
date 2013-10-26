# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	allacrost
PORTVERSION=	1.0.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-demo/${PORTVERSION}
DISTNAME=	${PORTNAME}_demo_source_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A single player 2D role-playing game

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		boost_thread:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENAL=	al
USE_LUA=	5.1
USE_SDL=	sdl ttf net
USE_GL=		yes
USE_GCC=	yes # problems in luabind
USES=		gettext

CONFIGURE_ARGS=	--datadir=${DATADIR}
CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR} -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	MANUAL

OPTIONS_DEFINE=	EDITOR DOCS
EDITOR_DESC=	Enable editor

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEDITOR}
QT_NONSTANDARD=	yes
USE_QT4+=	corelib gui opengl moc_build qt3support
CONFIGURE_ARGS+=--enable-editor=yes
PLIST_SUB=	EDITOR=""
.else
CONFIGURE_ARGS+=--enable-editor=no
PLIST_SUB=	EDITOR="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include/|-I${LOCALBASE}/include/|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|exit -1|exit 1|; /CXXFLAGS=/ d; \
		s|-lSDL |`${SDL_CONFIG} --libs` |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^LIBS =/ s|$$| @INTLLIBS@|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^bindir = / s|games|bin|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/qt4_incdirs/ s|".*"|"${QT_INCDIR}"|; \
		/qt4_libdirs/ s|".*"|"${QT_LIBDIR}"|; /test/ s|==|=|' \
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MEDITOR}
	@${REINPLACE_CMD} -e '/^INCLUDES = / s|=|= -I${QT_INCDIR}/QtGui \
		-I${QT_INCDIR}/QtOpenGL -I${QT_INCDIR}/Qt3Support \
		-I${QT_INCDIR}/QtCore -I${QT_INCDIR}|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
