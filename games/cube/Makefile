# New ports collection makefile for:	cube
# Date created:        17 October 2002
# Whom:                Arjan van Leeuwen
#
# $FreeBSD$
#

PORTNAME=	cube
PORTVERSION=	2004.05.22
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	An OpenGL 3D First Person Shooter game

EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

USE_SDL=	image mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/source/src
DATADIR=	${PREFIX}/share/cube
CONFIGURE_WRKSRC=	${WRKSRC}/source/enet

SUB_FILES=	cube_client cube_server

post-extract:
	@ ${UNZIP_CMD} -a -q -o ${WRKSRC}/source/${DISTNAME}_src.zip -d ${WRKSRC}/source/

post-patch:
	@${REINPLACE_CMD} -e 's|%%CXX%%|${CXX}|g ; \
		s|%%CXXFLAGS%%|${CXXFLAGS}|g ; s|%%X11BASE%%|${X11BASE}|g' \
			${BUILD_WRKSRC}/Makefile

pre-configure:
	@${CHMOD} u+x ${CONFIGURE_WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cube_client ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/cube_server ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cube_client ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cube_server ${PREFIX}/libexec
	${MKDIR} ${DATADIR}/savegames
	${CP} -Rp ${WRKSRC}/packages ${DATADIR}
	${CP} -Rp ${WRKSRC}/data ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/autoexec.cfg ${DATADIR}

.include <bsd.port.mk>
