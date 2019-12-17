# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	gemrb
PORTVERSION=	0.8.6
CATEGORIES=	games emulators
MASTER_SITES=	SF/${PORTNAME}/GemRB%20Sources/GemRB%20${PORTVERSION:.1=}%20Sources

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	GemRB (Game engine made with preRendered Background)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libfreetype.so:print/freetype2

OPTIONS_DEFINE=	DOCS OPENGL
OPTIONS_SUB=	yes

OPENGL_USES=	gl
OPENGL_USE=	gl=gl,glu,glew
OPENGL_CMAKE_ON=-DOPENGL_BACKEND=OpenGL

PLIST_SUB=	PORTVERSION=${PORTVERSION}
USES=		cmake gnome iconv localbase openal:al,alut python:2.7 sdl \
		shebangfix
SHEBANG_FILES=	admin/extend2da.py
USE_SDL=	sdl2
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DDOC_DIR="${DOCSDIR}" \
		-DMAN_DIR="${MAN6PREFIX}/man/man6/" \
		-DSDL_BACKEND=SDL2 \
		-DUSE_OPENAL=ON \
		-DUSE_LIBVLC=OFF \
		-DHAVE_LDEXPF=1

.include <bsd.port.mk>
