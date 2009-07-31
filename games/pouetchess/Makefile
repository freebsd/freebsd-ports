# New ports collection makefile for:	pouetChess
# Date created:				18 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	pouetchess
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	pouetChess_0.11_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An open-source 3D chess game

USE_SDL=	sdl image
USE_GL=		gl
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/pouetChess_0.11

DESKTOP_ENTRIES="pouetChess" \
		"Play chess" \
		"${DATADIR}/textures/1.png" \
		"pouetChess" \
		"Application;Game;" \
		false

post-patch:
	@${FIND} ${WRKSRC} \( -name "*.cpp" -o -name "*.h" -o -name Makefile \
		-o -name config.ini \) -exec ${REINPLACE_CMD} -e \
		"s|$$(${PRINTF} '\r')$$||" {} \;

	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^LIBS/ s|$$| -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/CXX	/ d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/CXXFLAGS.*+=/ d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|:=|+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CXXFLAGS/ s|$$| -I${LOCALBASE}/include|' ${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e 's|config\.ini|${PREFIX}/etc/pouetChess.conf|' ${WRKSRC}/src/globalInfos.cpp
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/src/globalInfos.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pouetChess ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/config.ini ${PREFIX}/etc/pouetChess.conf.sample
	if [ ! -f ${PREFIX}/etc/pouetChess.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/bin/config.ini ${PREFIX}/etc/pouetChess.conf; \
	fi
.for i in objets3d textures icons
	${MKDIR} ${DATADIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/bin/data/${i}/* ${DATADIR}/${i}
.endfor

.include <bsd.port.mk>
