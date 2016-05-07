# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	kiki
PORTVERSION=	1.0.2
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Kiki the nanobot is a 3-D puzzle game

BUILD_DEPENDS=	swig:devel/swig13

USES=		compiler dos2unix gmake python
USE_GL=		gl glu glut
USE_SDL=	sdl mixer image
DOS2UNIX_REGEX=	.*/(Makefile|.*\.cpp|.*\.h|.*\.i)$
MAKE_ENV=	PYTHON_VER=${PYTHON_VERSION:C/^python//}
CXXFLAGS+=	-include sys/limits.h -fpermissive

WRKSRC=		${WRKDIR}/kiki

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="kiki the nanobot" \
		"3-D puzzle game" \
		"" \
		"kiki" \
		"Game;LogicGame;" \
		false

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang"
# these are critical, detect them if possible
CXXFLAGS+=	-Werror=tautological-constant-out-of-range-compare
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|.*|CXXFLAGS+=$$(KODI_INCLUDES) -I${LOCALBASE}/include `${SDL_CONFIG} --cflags`|' ${WRKSRC}/kodilib/linux/Makefile
	@${REINPLACE_CMD} -e 's|getenv("KIKI_HOME")|"${DATADIR}"|' ${WRKSRC}/src/main/KikiController.cpp

do-build:
	cd ${WRKSRC}/SWIG && swig -c++ -python -globals kiki -o KikiPy_wrap.cpp KikiPy.i
	cd ${WRKSRC}/kodilib/linux && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS}
	cd ${WRKSRC}/linux && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/kiki ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "py sound" ${STAGEDIR}${DATADIR}/

.include <bsd.port.post.mk>
