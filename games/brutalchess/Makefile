PORTNAME=	brutalchess
PORTVERSION=	0.5.2
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-alpha/${PORTNAME}-alpha-${PORTVERSION}
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}-src

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Nice looking OpenGL chess game
WWW=		http://brutalchess.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		dos2unix gl gmake libtool pkgconfig sdl xorg
USE_GL=		glu
USE_SDL=	sdl image
USE_XORG=	x11 xext xt xmu xi

DOS2UNIX_FILES=	brutalchess.nsi \
		fonts/!pizzadude.txt \
		models/debug.obj \
		NEWS \
		README \
		src/board.cpp \
		src/board.h \
		src/boardmove.cpp \
		src/brutalchess.cpp \
		src/brutalplayer.cpp

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
BINARY_ALIAS=	freetype-config=true
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-build:
	${CHMOD} 0755 ${WRKSRC}/install-sh

.include <bsd.port.mk>
