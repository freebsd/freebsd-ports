# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	repng2jpeg
PORTVERSION=	1.0.4
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://bsdforge.com/projects/source/graphics/repng2jpeg/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Tool to recompress JPEG/PNG/GIF

LICENSE=	GPLv1

USES=		tar:xz

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgd

PLIST_FILES=	bin/repng2jpeg

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/src/repng2jpeg \
		${WRKSRC}/src/repng2jpeg.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/repng2jpeg ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
