# New ports collection makefile for:	glpng
# Date created:		06 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	glpng
PORTVERSION=	1.45
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.wyatt100.freeserve.co.uk/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	glpng

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to easily load PNG files as an OpenGL textures

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GL=		gl
USE_ZIP=	yes
USE_LDCONFIG=	yes

AR?=		/usr/bin/ar

WRKSRC=		${WRKDIR}/src

post-patch:
	@${REINPLACE_CMD} -e 's|png/|libpng/|' ${WRKSRC}/glpng.c

do-build:
	${CC} ${CFLAGS} -fPIC -I${LOCALBASE}/include -I${WRKDIR}/include -c -o ${WRKSRC}/libglpng.o ${WRKSRC}/glpng.c
	${CC} ${CFLAGS} -fPIC -L${LOCALBASE}/lib -shared -lGL -lpng -lz -lm -o ${WRKSRC}/libglpng.so.1 ${WRKSRC}/libglpng.o
	${AR} cqs ${WRKSRC}/libglpng.a ${WRKSRC}/libglpng.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/libglpng.so.1 ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libglpng.a ${PREFIX}/lib
	${LN} -sf libglpng.so.1 ${PREFIX}/lib/libglpng.so
	${MKDIR} ${PREFIX}/include/GL/
	${INSTALL_DATA} ${WRKDIR}/include/GL/glpng.h ${PREFIX}/include/GL/

.include <bsd.port.mk>
