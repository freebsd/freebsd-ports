# New ports collection makefile for: fife
# Date created:      19 May 2012
# Whom:              GreenDog <fiziologus@gmail.com>
#
# $FreeBSD$

PORTNAME=		fife
PORTVERSION=		0.3.3r3
PORTREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://sourceforge.net/projects/${PORTNAME}/files/active/src/:source \
			http://sourceforge.net/projects/${PORTNAME}/files/active/demos/:demo
DISTNAME=		${PORTNAME}_${PORTVERSION}
DISTFILES+=	      	${DISTNAME}.tar.gz:source \
			${DISTNAME}_demos.tar.gz:demo

MAINTAINER=		fiziologus@gmail.com
COMMENT=		Flexible Isometric Free Engine

FETCH_ARGS=		-Fpr

BUILD_DEPENDS=		${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13

LIB_DEPENDS=		vorbisfile.6:${PORTSDIR}/audio/libvorbis \
			guichan.2:${PORTSDIR}/devel/guichan \
			boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
			png15:${PORTSDIR}/graphics/png

USE_SDL=		sdl ttf image
USE_OPENAL=		al

USE_SCONS=		yes
SCONS_BUILDENV=		SWIG=${LOCALBASE}/bin/swig \
			CXX=${CXX} CPP=${CPP}
SCONS_TARGET=		fife-python
SCONS_INSTALL_TARGET=	install-python

USE_PYTHON=		yes

USE_XORG=		xcursor
USE_GL=			gl

USE_GNOME=		pkgconfig

post-patch:
	${REINPLACE_CMD} -e 's/X11R6/local/g' ${WRKSRC}/build/openbsd4-config.py && \
		${MV} ${WRKSRC}/build/openbsd4-config.py ${WRKSRC}/build/${PYTHON_PLATFORM}-config.py

post-install:
	${MKDIR} ${DATADIR}
	${MV} ${WRKSRC}/tools ${DATADIR}
	${MV} ${WRKDIR}/demos ${DATADIR}
	${MKDIR} ${DOCSDIR}
.for FILE in README AUTHORS CHANGES COPYING
	${MV} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
