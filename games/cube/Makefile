# New ports collection makefile for:	cube
# Date created:        17 October 2002
# Whom:                Arjan van Leeuwen
#
# $FreeBSD$
#

PORTNAME=	cube
PORTVERSION=	2002.10.20
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://tunes.org/~eihrul/ \
		http://www.idi.ntnu.no/~jonasf/cube/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/:S/./_/}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	An OpenGL 3D First Person Shooter game

USE_SDL=	image mixer sdl
USE_ZIP=	yes
USE_GMAKE=	yes

BUILD_WRKSRC=	${WRKSRC}/source/src
EXTRACT_BEFORE_ARGS=-q -a
EXTRACT_AFTER_ARGS=-d ${WRKDIR}/${DISTNAME}/
DATADIR=	${PREFIX}/share/cube

post-extract:
	@ unzip -a -q -o ${WRKSRC}/source/${DISTNAME}_src.zip -d ${WRKSRC}/source/

post-patch:
	${ECHO_CMD} '#define DATADIR "${DATADIR}"' >> ${BUILD_WRKSRC}/cube.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cube_client ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cube_server ${PREFIX}/bin
	${MKDIR} ${DATADIR}/savegames
	${CP} -Rp ${WRKSRC}/packages ${DATADIR}
	${CP} -Rp ${WRKSRC}/data ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/autoexec.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/servers.cfg ${DATADIR}

.include <bsd.port.mk>
