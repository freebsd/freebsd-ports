# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	bmp2html
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	CRITICAL
DISTNAME=	${PORTNAME}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	BMP to HTML converter

USE_SDL=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
SDL_FLAGS=	-I${LOCALBASE}/include/SDL -I${LOCALBASE}/include
EXTRA_LDFLAGS=	-lSDL -pthread
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
