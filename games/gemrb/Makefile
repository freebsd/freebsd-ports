# $FreeBSD$

PORTNAME=	gemrb
PORTVERSION=	0.7.2
CATEGORIES=	games emulators
MASTER_SITES=	SF/${PORTNAME}/GemRB%20Sources/GemRB%20${PORTVERSION}%20Sources

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	GemRB (Game engine made with preRendered Background)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_CMAKE=	yes
USE_SDL=	sdl mixer ttf
USE_OPENAL=	al alut
USE_LDCONFIG=	yes
USE_PYTHON=	2.6+
CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
CMAKE_C_FLAGS=	${CFLAGS}
CMAKE_ARGS=	-DDOC_DIR="${DOCSDIR}" -DMAN_DIR="${MAN6PREFIX}/man/man6/" -DDISABLE_WERROR=1 -DINSOURCEBUILD=1

.include <bsd.port.options.mk>

MAN6=		gemrb.6

post-patch:
	@${REINPLACE_CMD} \
	-e '/^ADD_SUBDIRECTORY( VLCPlayer )/d' \
	${WRKSRC}/gemrb/plugins/CMakeLists.txt

.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} \
	-e '/^INSTALL( FILES README INSTALL COPYING NEWS AUTHORS DESTINATION \$${DOC_DIR} )/d' \
	${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} \
	-e '/^ADD_SUBDIRECTORY( docs )/d' \
	${WRKSRC}/gemrb/CMakeLists.txt
	@${REINPLACE_CMD} \
	-e '/^ADD_SUBDIRECTORY( en )/d' \
	${WRKSRC}/gemrb/docs/CMakeLists.txt
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/gemrb.cfg ]; then \
		${CP} ${WRKSRC}/gemrb/GemRB.cfg.sample ${PREFIX}/etc/gemrb.cfg; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
