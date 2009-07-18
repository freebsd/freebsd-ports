# New ports collection makefile for:	allacrost
# Date created:		03 Oct 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	allacrost
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	allacrost_demo_source_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A single player 2D role-playing game

BUILD_DEPENDS=	${LOCALBASE}/lib/libluabind.a:${PORTSDIR}/devel/luabind
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		openal.0:${PORTSDIR}/audio/openal \
		ogg.6:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LUA=	5.0
USE_SDL=	sdl ttf net
USE_GL=		yes
USE_GCC=	4.2+
USE_GETTEXT=	yes

CONFIGURE_ARGS=	--datadir=${DATADIR}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}"
USE_QT_VER=	4
QT_COMPONENTS=	# none by default
QT_NONSTANDARD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	MANUAL

OPTIONS=	EDITOR "Enable editor" off

.include <bsd.port.pre.mk>

.if defined(WITH_EDITOR)
QT_COMPONENTS+=	corelib gui opengl moc_build qt3support
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
.if defined(WITH_EDITOR)
	@${REINPLACE_CMD} -e '/^INCLUDES = / s|=|= -I${QT_INCDIR}/QtGui \
		-I${QT_INCDIR}/QtOpenGL -I${QT_INCDIR}/Qt3Support \
		-I${QT_INCDIR}/QtCore -I${QT_INCDIR}|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
