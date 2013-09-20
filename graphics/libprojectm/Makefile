# Created by: utisoft@gmail.com
# $FreeBSD$

PORTNAME=	libprojectM
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	graphics audio
MASTER_SITES=	SF/${PORTNAME:L:S/lib//}/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/lib//}-${DISTVERSION}-Source

MAINTAINER=	crees@FreeBSD.org
COMMENT=	An awesome music visualiser

LICENSE=	LGPL21

LIB_DEPENDS=	ftgl:${PORTSDIR}/graphics/ftgl \
		GLEW:${PORTSDIR}/graphics/glew \
		freetype:${PORTSDIR}/print/freetype2

USES=		cmake
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
# Install config.inp.sample instead of overwriting user's file.
# Needs to be specific enough not to rename config.inp.in too!
# Also correct pkgconfig destination dir -- fiddly
	@${REINPLACE_CMD} -e 's/config.inp\([\" ]\)/config.inp.sample\1/' \
			-e 's#\(/lib\)[^}]*}\(/pkgconfig\)#\1data\2#' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's#/usr/X11R6#${LOCALBASE}#' \
		${WRKSRC}/cmake/FindFreetype2.cmake
# Fix empty libdir in pkgconfig file to stop vlc complaining
	@${REINPLACE_CMD} -e 's#^\(libdir=\).*#\1${PREFIX}/lib#' \
		${WRKSRC}/${PORTNAME}.pc.in

post-install:
	@if [ ! -f ${PREFIX}/share/projectM/config.inp ]; then \
		${CP} -p ${PREFIX}/share/projectM/config.inp.sample \
			${PREFIX}/share/projectM/config.inp ; \
	fi

.include <bsd.port.mk>
