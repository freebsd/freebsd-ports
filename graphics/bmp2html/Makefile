# New ports collection makefile for:	bmp2html
# Date created:				10 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bmp2html
PORTVERSION=	0.1
CATEGORIES=	graphics
MASTER_SITES=	http://critical.ch/distfiles/
MASTER_SITES+=	http://www.dasfisk.dk/bmp2html/
DISTNAME=	${PORTNAME}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A bmp to html converter

USE_SDL=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
SDL_FLAGS=	-I${LOCALBASE}/include/SDL11
EXTRA_LDFLAGS=	-lSDL-1.1 -pthread
DEFINES=	-D_REENTRANT

PLIST_FILES=	bin/bmp2html

post-patch:
	@${RM} ${WRKSRC}/${PORTNAME}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${SDL_FLAGS} ${DEFINES} -c \
		-o ${WRKSRC}/${PORTNAME}.o ${WRKSRC}/${PORTNAME}.c
	${CC} ${CFLAGS} ${LDFLAGS} ${SDL_FLAGS} ${EXTRA_LDFLAGS} \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
