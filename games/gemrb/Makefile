PORTNAME=	gemrb
PORTVERSION=	0.9.1
CATEGORIES=	games emulators
MASTER_SITES=	SF/${PORTNAME}/Releases/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-sources

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	GemRB (Game engine made with preRendered Background)
WWW=		https://www.gemrb.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c11 gnome iconv localbase openal:al,alut \
		python sdl shebangfix
SHEBANG_FILES=	admin/extend2da.py
USE_SDL=	sdl2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

CMAKE_ARGS=	-DDOC_DIR="${DOCSDIR}" \
		-DMAN_DIR="${MAN6PREFIX}/man/man6/" \
		-DSDL_BACKEND=SDL2 \
		-DUSE_OPENAL=ON \
		-DUSE_LIBVLC=OFF \
		-DHAVE_LDEXPF=1

PLIST_SUB=	PORTVERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
