# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simpleviewer
PORTVERSION=	1.7.1553.8560
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OpenGL%20edition
DISTNAME=	sviewgl-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and simple OpenGL image viewer with transparency support

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		gif.5:${PORTSDIR}/graphics/giflib

USE_BZIP2=	yes
USE_EFL=	imlib2
USE_GL=		glut
WRKSRC=		${WRKDIR}/sviewgl-src
CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ARGS=	CC=${CXX}

PLIST_FILES=	bin/sviewgl

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,${CFLAGS}, ; s,/usr/include,${LOCALBASE}/include,g ; \
		s,=-s,=-L${LOCALBASE}/lib,' ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sviewgl ${PREFIX}/bin

.include <bsd.port.post.mk>
