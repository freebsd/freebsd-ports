# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=		fife
PORTVERSION=		0.3.5
CATEGORIES=		games
MASTER_SITES=		http://sourceforge.net/projects/${PORTNAME}/files/active/src/:source \
			http://sourceforge.net/projects/${PORTNAME}/files/active/demos/:demo \
			http://sourceforge.net/projects/${PORTNAME}/files/active/tools/:tools
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		${PORTNAME}_${PORTVERSION}
DISTFILES+=	      	${DISTNAME}.tar.gz:source \
			${DISTNAME}_demos.tar.gz:demo \
			${DISTNAME}_tools.tar.gz:tools

MAINTAINER=		fiziologus@gmail.com
COMMENT=		Flexible Isometric Free Engine

LICENSE=		LGPL21

BUILD_DEPENDS=		${LOCALBASE}/bin/swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
			libguichan.so:${PORTSDIR}/devel/guichan \
			libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
			libpng15.so:${PORTSDIR}/graphics/png

USES=			openal:al pkgconfig scons
USE_GL=			gl
USE_PYTHON=		2
USE_SDL=		sdl ttf image
USE_XORG=		xcursor

ALL_TARGET=		fife-python
INSTALL_TARGET=		install-python
MAKE_ENV+=		SWIG=${LOCALBASE}/bin/swig2.0

post-patch:
	${REINPLACE_CMD} -e 's/X11R6/local/g; s/libpng/ligpng15/g' ${WRKSRC}/build/openbsd4-config.py && \
		${MV} ${WRKSRC}/build/openbsd4-config.py ${WRKSRC}/build/${PYTHON_PLATFORM}-config.py

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MV} ${WRKDIR}/tools ${STAGEDIR}${DATADIR}
	${MV} ${WRKDIR}/demos ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in README AUTHORS CHANGES COPYING
	${MV} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
