# New ports collection Makefile for:	libprojectM
# Date created:	 	8 December 2010
# Whom:			utisoft@gmail.com
#
# $FreeBSD$
#

PORTNAME=	libprojectM
PORTVERSION=	2.0.1
CATEGORIES=	graphics audio
MASTER_SITES=	SF/${PORTNAME:L:S/lib//}/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/lib//}-${DISTVERSION}-Source

MAINTAINER=	utisoft@gmail.com
COMMENT=	An awesome music visualiser

LICENSE=	LGPL21

LIB_DEPENDS=	ftgl:${PORTSDIR}/graphics/ftgl \
		GLEW:${PORTSDIR}/graphics/glew \
		freetype:${PORTSDIR}/print/freetype2

USE_CMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
USE_LDCONFIG=	yes

post-patch:
# Install config.inp.sample instead of overwriting user's file.
# Needs to be specific enough not to rename config.inp.in too!
	@${REINPLACE_CMD} -e 's/config.inp\([\" ]\)/config.inp.sample\1/' \
			-e 's#/pkgconfig#data/pkgconfig#' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's#/usr/X11R6#${LOCALBASE}#' \
		${WRKSRC}/cmake/FindFreetype2.cmake

post-install:
	@if [ ! -f ${PREFIX}/share/projectM/config.inp ]; then \
		${CP} -p ${PREFIX}/share/projectM/config.inp.sample \
			${PREFIX}/share/projectM/config.inp ; \
	fi

.include <bsd.port.mk>
