# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=		fife
PORTVERSION=		0.3.5
PORTREVISION=		7
CATEGORIES=		games
MASTER_SITES=		http://sourceforge.net/projects/${PORTNAME}/files/active/src/:source \
			http://sourceforge.net/projects/${PORTNAME}/files/active/demos/:demo \
			http://sourceforge.net/projects/${PORTNAME}/files/active/tools/:tools
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		${PORTNAME}_${PORTVERSION}
DISTFILES+=		${DISTNAME}.tar.gz:source \
			${DISTNAME}_demos.tar.gz:demo \
			${DISTNAME}_tools.tar.gz:tools

MAINTAINER=		fiziologus@gmail.com
COMMENT=		Flexible Isometric Free Engine

LICENSE=		LGPL21

BUILD_DEPENDS=		${LOCALBASE}/bin/swig2.0:devel/swig20
LIB_DEPENDS=		libvorbisfile.so:audio/libvorbis \
			libguichan.so:devel/guichan \
			libboost_filesystem.so:devel/boost-libs \
			libpng.so:graphics/png

USES=			openal:al pkgconfig python:2 scons
USE_GL=			gl
USE_SDL=		sdl ttf image
USE_XORG=		xcursor

ALL_TARGET=		fife-python
INSTALL_TARGET=		install-python
MAKE_ENV+=		SWIG=${LOCALBASE}/bin/swig2.0

OPTIONS_DEFINE=		DOCS

post-patch:
	${REINPLACE_CMD} -e 's/X11R6/local/g; s/libpng/ligpng15/g' ${WRKSRC}/build/openbsd4-config.py && \
		${MV} ${WRKSRC}/build/openbsd4-config.py ${WRKSRC}/build/${PYTHON_PLATFORM}-config.py

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MV} ${WRKDIR}/tools ${STAGEDIR}${DATADIR}
	${MV} ${WRKDIR}/demos ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in README AUTHORS CHANGES COPYING
	${MV} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
