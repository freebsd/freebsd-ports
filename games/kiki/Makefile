# New ports collection makefile for:	kiki
# Date created:		24 Oct 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	kiki
PORTVERSION=	1.0.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Kiki the nanobot is a 3-D puzzle game

USE_PYTHON=	2.3
USE_GMAKE=	yes
USE_GL=		glut
USE_SDL=	sdl mixer image
USE_DOS2UNIX=	kodilib/linux/Makefile src/main/KikiController.cpp linux/Makefile kodilib/src/types/KVector.h src/main/KikiPythonWidget.h

WRKSRC=		${WRKDIR}/kiki

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|.*|CXXFLAGS+=$$(KODI_INCLUDES) -I${LOCALBASE}/include `${SDL_CONFIG} --cflags`|' ${WRKSRC}/kodilib/linux/Makefile
	@${REINPLACE_CMD} -e '/^X11_INCLUDES/ s|/.*/|${LOCALBASE}/include|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e '/PYTHON/ s|/usr|${LOCALBASE}|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|CXXFLAGS =|CXXFLAGS +=|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|PYTHON_VERSION|PYTHON_VER|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e '/^GLLIBS/ s|$$| -L${LOCALBASE}/lib|' ${WRKSRC}/linux/Makefile
	@${REINPLACE_CMD} -e 's|getenv("KIKI_HOME")|"${DATADIR}"|' ${WRKSRC}/src/main/KikiController.cpp

do-build:
	@cd ${WRKSRC}/kodilib/linux && ${SETENV} ${MAKE_ENV} ${GMAKE}
	@cd ${WRKSRC}/linux && ${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/kiki ${PREFIX}/bin
.for d in py sound
	@cd ${WRKSRC}/${d} && \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/${d}/{} \; ;\
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/${d}/{} \;
.endfor

.include <bsd.port.mk>
