# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brainparty
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.tuxradar.com/files/brainparty/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Family-friendly set of 36 puzzle games

USES=		gmake
USE_SDL=	sdl mixer ttf gfx image
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|Content/|${DATADIR}/|' ${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Content/* ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
