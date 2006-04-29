# New ports collection makefile for:	fishsupper
# Date created:		25 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	fishsupper
PORTVERSION=	0.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Guide a cat across a series of rivers, jumping from log to log

USE_GMAKE=	yes
USE_SDL=	sdl image mixer

ALL_TARGET=	fishsupper
WRKSRC=		${WRKDIR}/FishSupper
BUILD_WRKSRC=	${WRKSRC}/src

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|g++|${CXX} ${CXXFLAGS}|' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/src/getreadydisplay.cc \
		${WRKSRC}/src/playdisplay.cc ${WRKSRC}/src/playmodel.cc \
		${WRKSRC}/src/soundengine.cc ${WRKSRC}/src/titlescreendisplay.cc
	@${REINPLACE_CMD} -e '/filename/ s|\[[0-9][0-9]*\]|[1024]|' ${WRKSRC}/src/playdisplay.cc \
		${WRKSRC}/src/playmodel.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fishsupper ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for d in images levels sounds
	${MKDIR} ${DATADIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/data/${d}/* ${DATADIR}/${d}/
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
