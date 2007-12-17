# New ports collection makefile for:	odamex
# Date created:				2007-12-06
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	odamex
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	Odamex-${PORTVERSION}-src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	The Standard in Online Multiplayer Doom

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|; s|-DUNIX|${CFLAGS} &|; \
		s|sdl11-config|sdl-config|; s|/usr/X11R6|${LOCALBASE}|' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|%%DMDIR%%|${DMDIR}|; \
		s|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/client/src/d_main.cpp

do-install:
.for f in odamaster odamex odasrv
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/odamex.wad ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
