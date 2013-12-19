# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	pipepanic
PORTVERSION=	0.1.3
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.users.waitrose.com/~thunor/pipepanic/dload/ \
		LOCAL/ehaupt \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A pipe connecting game using libSDL

USE_SDL=	sdl

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e '/^#define DATADIR/ s|.*|#define DATADIR "${DATADIR}/"|' \
			${WRKSRC}/main.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
