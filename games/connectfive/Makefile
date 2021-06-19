PORTNAME=	connectfive
PORTVERSION=	1.0.2
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-linux/${PORTNAME}-${PORTVERSION}
DISTNAME=	connectFive

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Place five pieces in a row on a 3D board

USES=		dos2unix gl gmake sdl xorg
USE_SDL=	sdl
USE_GL=		gl
USE_XORG=	xmu xext x11
DOS2UNIX_FILES=	glfont2.h

MAKEFILE=	Makefile.linux
ALL_TARGET=	default
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/connectFive

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile.linux
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/connect.cpp
	@${REINPLACE_CMD} -e 's|Board::||' ${WRKSRC}/Board.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.txt ${WRKSRC}/LICENSE.txt ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
