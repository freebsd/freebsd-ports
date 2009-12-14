# New ports collection makefile for:	kiki
# Date created:		24 Oct 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	kiki
PORTVERSION=	1.0.2
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Kiki the nanobot is a 3-D puzzle game

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_PYTHON=	2.3+
USE_GMAKE=	yes
USE_GL=		gl glu glut
USE_SDL=	sdl mixer image
USE_DOS2UNIX=	kodilib/linux/Makefile src/main/KikiController.cpp linux/Makefile kodilib/src/types/KVector.h src/main/KikiPythonWidget.h
MAKE_ENV=	PYTHON_VER=${PYTHON_VERSION:C/^python//}
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/kiki

DESKTOP_ENTRIES="kiki the nanobot" \
		"3-D puzzle game" \
		"" \
		"kiki" \
		"Game;LogicGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|.*|CXXFLAGS+=$$(KODI_INCLUDES) -I${LOCALBASE}/include `${SDL_CONFIG} --cflags`|' ${WRKSRC}/kodilib/linux/Makefile
	@${REINPLACE_CMD} -e 's|getenv("KIKI_HOME")|"${DATADIR}"|' ${WRKSRC}/src/main/KikiController.cpp

do-build:
	cd ${WRKSRC}/SWIG && swig -c++ -python -globals kiki -o KikiPy_wrap.cpp KikiPy.i
	cd ${WRKSRC}/kodilib/linux && ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS}
	cd ${WRKSRC}/linux && ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/kiki ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "py sound" ${DATADIR}/

.include <bsd.port.mk>
