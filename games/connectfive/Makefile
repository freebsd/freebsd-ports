# New ports collection makefile for:	connectfive
# Date created:			20 Sep 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	connectfive
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-linux/${PORTNAME}-${PORTVERSION}
DISTNAME=	connectFive

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Place five pieces in a row on a 3D board

MAKEFILE=	Makefile.linux
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	default
CPPFLAGS+=	-I${LOCALBASE}/include

USE_SDL=	sdl
USE_GL=		gl
USE_XORG=	xmu xext x11
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/connectFive

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile.linux
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/connect.cpp
	@${REINPLACE_CMD} -e 's|Board::||' ${WRKSRC}/Board.h

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/connectfive ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.txt ${WRKSRC}/LICENSE.txt ${WRKSRC}/README.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
