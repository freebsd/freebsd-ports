# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	repng2jpeg
PORTVERSION=	1.0.5
CATEGORIES=	graphics
MASTER_SITES=	http://bsdforge.com/projects/source/graphics/repng2jpeg/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Small tool to recompress JPEG, PNG, and GIF images

LICENSE=	GPLv1

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		tar:xz

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgd

PLIST_FILES=	bin/repng2jpeg

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/src/repng2jpeg \
		${WRKSRC}/src/repng2jpeg.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/repng2jpeg ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
