# Created by: Travis Poppe <tlp@liquidx.org>

PORTNAME=	stratagus
PORTVERSION=	2.4.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free cross-platform real-time strategy gaming engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtolua++-${LUA_VER}.so:lang/tolua++

USE_GITHUB=	yes
GH_ACCOUNT=	Wargus

USES=		cmake compiler:c++11-lang gl lua:51 pkgconfig sdl sqlite python:run
USE_GL=		gl glu
USE_SDL=	sdl
CMAKE_ARGS=	-DGAMEDIR:STRING="bin" \
		-DTOLUA++_APP:STRING="tolua++-${LUA_VER}" \
		-DTOLUA++_INCLUDE_DIR:STRING="${LUA_INCDIR}" \
		-DTOLUA++_LIBRARY:STRING="${LUA_LIBDIR}/libtolua++.so"
CMAKE_ON=	ENABLE_DEV

PORTDOCS=	*

OPTIONS_DEFINE=	MIKMOD MNG THEORA VORBIS X11 FLUIDSYNTH DOCS
OPTIONS_DEFAULT=MIKMOD MNG THEORA VORBIS X11 FLUIDSYNTH

MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MIKMOD_CMAKE_BOOL=	WITH_MIKMOD

MNG_DESC=		MNG image library support
MNG_LIB_DEPENDS=	libmng.so:graphics/libmng
MNG_CMAKE_BOOL=		WITH_MNG

THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CMAKE_BOOL=	WITH_THEORA

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CMAKE_BOOL=	WITH_OGGVORBIS

X11_DESC=		X11 clipboard pasting support
X11_USES=		xorg
X11_USE=		XORG=x11
X11_CMAKE_BOOL=		WITH_X11

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_BOOL=	WITH_FLUIDSYNTH

post-patch:
	@${REINPLACE_CMD} -e 's|"python"|"${PYTHON_CMD}"|' \
		${WRKSRC}/gameheaders/stratagus-tinyfiledialogs.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/stratagus.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

post-install-DOCS-on:
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "[a-z]*.html *.txt graphics scripts" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-c++11-narrowing
.else
CXXFLAGS+=	-Wno-error
.endif

.include <bsd.port.post.mk>
