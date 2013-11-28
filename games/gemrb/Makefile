# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	gemrb
PORTVERSION=	0.8.0.1
CATEGORIES=	games emulators
MASTER_SITES=	SF/${PORTNAME}/GemRB%20Sources/GemRB%20${PORTVERSION:.1=}%20Sources

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	GemRB (Game engine made with preRendered Background)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USES=		cmake
USE_SDL=	sdl mixer ttf
USE_OPENAL=	al alut
USE_LDCONFIG=	yes
USE_PYTHON=	2.6+
CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
CMAKE_C_FLAGS=	${CFLAGS}
CMAKE_ARGS=	-DDOC_DIR="${DOCSDIR}" -DMAN_DIR="${MAN6PREFIX}/man/man6/" -DDISABLE_WERROR=1 -DINSOURCEBUILD=1

.include <bsd.port.mk>
