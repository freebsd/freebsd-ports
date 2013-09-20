# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=		fife
PORTVERSION=		0.3.4
CATEGORIES=		games
MASTER_SITES=		http://sourceforge.net/projects/${PORTNAME}/files/active/src/:source \
			http://sourceforge.net/projects/${PORTNAME}/files/active/demos/:demo \
			http://sourceforge.net/projects/${PORTNAME}/files/active/tools/:tools
DISTNAME=		${PORTNAME}_${PORTVERSION}
DISTFILES+=	      	${DISTNAME}.tar.gz:source \
			${DISTNAME}_demos.tar.gz:demo \
			${DISTNAME}_tools.tar.gz:tools

MAINTAINER=		fiziologus@gmail.com
COMMENT=		Flexible Isometric Free Engine

BUILD_DEPENDS=		${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13

LIB_DEPENDS=		vorbisfile:${PORTSDIR}/audio/libvorbis \
			guichan:${PORTSDIR}/devel/guichan \
			boost_filesystem:${PORTSDIR}/devel/boost-libs \
			png15:${PORTSDIR}/graphics/png

FETCH_ARGS=		-Fpr

USE_SDL=		sdl ttf image
USE_OPENAL=		al

USE_SCONS=		yes
SCONS_ARGS=		--prefix=${PREFIX} --python-prefix=${PYTHON_SITELIBDIR}
SCONS_BUILDENV=		SWIG=${LOCALBASE}/bin/swig \
			CXX=${CXX}
SCONS_TARGET=		fife-python
SCONS_INSTALL_TARGET=	install-python

USE_PYTHON=		2.7

USE_XORG=		xcursor
USE_GL=			gl

USES=			pkgconfig

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's/X11R6/local/g; s/libpng/ligpng15/g' ${WRKSRC}/build/openbsd4-config.py && \
		${MV} ${WRKSRC}/build/openbsd4-config.py ${WRKSRC}/build/${PYTHON_PLATFORM}-config.py

post-install:
	${MKDIR} ${DATADIR}
	${MV} ${WRKDIR}/tools ${DATADIR}
	${MV} ${WRKDIR}/demos ${DATADIR}
	${MKDIR} ${DOCSDIR}
.for FILE in README AUTHORS CHANGES COPYING
	${MV} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
