# New ports collection makefile for:	stellarium
# Date created:			26 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	stellarium
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A 3D photo-realistic sky renderer

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		curl.4:${PORTSDIR}/ftp/curl \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc gui rcc uic opengl
USE_GETTEXT=	yes
USE_GL=		yes
USE_SDL=	sdl mixer
USE_XLIB=	yes
USE_GMAKE=	yes
CMAKE_ENV=	QMAKESPEC=${QMAKESPEC}
CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING='${CC}' \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_CXX_COMPILER:STRING=${CXX} \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_EXE_LINKER_FLAGS:STRING="${PTHREAD_LIBS}" \
		-DCMAKE_THREAD_LIBS:STRING="${PTHREAD_LIBS}" \
		-DCMAKE_USE_PTHREADS:BOOL=ON \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DFreeType2_INCLUDE_DIR=${LOCALBASE}/include/freetype2 \
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

do-configure:
	@(cd ${WRKSRC}; \
	${CMAKE_ENV} ${LOCALBASE}/bin/cmake ${CMAKE_ARGS} ${PATCH_WRKSRC})

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
