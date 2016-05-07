# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	glpng
PORTVERSION=	1.45
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://www.wyatt100.freeserve.co.uk/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	glpng

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to easily load PNG files as an OpenGL textures

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png

USE_GL=		gl
USES=		dos2unix zip
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	glpng.c

AR?=		/usr/bin/ar

WRKSRC=		${WRKDIR}/src

do-build:
	${CC} ${CFLAGS} -fPIC -I${LOCALBASE}/include -I${WRKDIR}/include -c -o ${WRKSRC}/libglpng.o ${WRKSRC}/glpng.c
	${CC} ${CFLAGS} -fPIC -L${LOCALBASE}/lib -shared -Wl,-soname,libglpng.so.1 -lGL -lpng -lz -lm -o ${WRKSRC}/libglpng.so.1 ${WRKSRC}/libglpng.o
	${AR} cqs ${WRKSRC}/libglpng.a ${WRKSRC}/libglpng.o

do-install:
	${INSTALL_LIB} ${WRKSRC}/libglpng.so.1 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libglpng.a ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libglpng.so.1 ${STAGEDIR}${PREFIX}/lib/libglpng.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/GL/
	${INSTALL_DATA} ${WRKDIR}/include/GL/glpng.h ${STAGEDIR}${PREFIX}/include/GL/

.include <bsd.port.mk>
