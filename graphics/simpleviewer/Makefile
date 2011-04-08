# New ports collection makefile for:	Simple Viewer GL
# Date created:				08 Apr 2011
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	simpleviewer
PORTVERSION=	1.7.1553.8560
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OpenGL%20edition
DISTNAME=	sviewgl-src-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small and simple OpenGL image viewer with transparency support

LICENSE=	GPLv2

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_BZIP2=	yes
USE_EFL=	imlib2
USE_GL=		glut
WRKSRC=		${WRKDIR}/sviewgl-src
MAKE_ARGS=	CC=${CXX}

PLIST_FILES=	bin/sviewgl

post-patch:
# Respect CFLAGS, prefer more widely used libungif instead of giflib
	@${REINPLACE_CMD} -e 's,-O2,${CFLAGS}, ; s,/usr,${LOCALBASE},g ; \
		s,=-s,=-L${LOCALBASE}/lib, ; s,lgif,lungif,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,const struct dirent,struct dirent,' \
		${WRKSRC}/src/fileslist.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sviewgl ${PREFIX}/bin

.include <bsd.port.mk>
