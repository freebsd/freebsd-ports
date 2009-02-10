# New ports collection makefile for:	Stellarium
# Date created:				26 Jan 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	stellarium
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A 3D photo-realistic sky renderer

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		curl.5:${PORTSDIR}/ftp/curl \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

BROKEN=		does not compile

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc gui rcc uic opengl
USE_GETTEXT=	yes
USE_GL=		yes
USE_SDL=	sdl mixer
USE_GMAKE=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_ENV+=	QMAKESPEC=${QMAKESPEC}
CMAKE_ARGS+=	-DFreeType2_INCLUDE_DIR=${LOCALBASE}/include/freetype2 \
		-DQT_QMAKE_EXECUTABLE=${QMAKE}

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

DESKTOP_ENTRIES="Stellarium" \
		"View the sky" \
		"${DATADIR}/data/stellarium.ico" \
		"stellarium" \
		"" \
		false

# avoid picking up the wrong fixx11h.h (x11/kdelibs3 installs one that
# doesn't handle FontChange)
post-patch:
	@${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -i '' -e 's/fixx11h.h/fixx11qt4h.h/'
	@${MV} ${WRKSRC}/src/stelutils/fixx11h.h ${WRKSRC}/src/stelutils/fixx11qt4h.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
