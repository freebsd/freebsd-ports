# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	kiki
PORTVERSION=	1.0.2
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Kiki the nanobot is a 3-D puzzle game

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	swig3.0:devel/swig30

USES=		compiler dos2unix gl gmake python:2.7 sdl
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

.if ${OSVERSION} > 1200031
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ino64
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|.*|CXXFLAGS+=$$(KODI_INCLUDES) -I${LOCALBASE}/include `${SDL_CONFIG} --cflags`|' ${WRKSRC}/kodilib/linux/Makefile
	@${REINPLACE_CMD} -e 's|getenv("KIKI_HOME")|"${DATADIR}"|' ${WRKSRC}/src/main/KikiController.cpp

do-build:
	cd ${WRKSRC}/SWIG && swig3.0 -c++ -python -globals kiki -o KikiPy_wrap.cpp KikiPy.i
	cd ${WRKSRC}/kodilib/linux && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS}
	cd ${WRKSRC}/linux && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/kiki ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "py sound" ${STAGEDIR}${DATADIR}/

.include <bsd.port.post.mk>
