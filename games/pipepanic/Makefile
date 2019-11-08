# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	pipepanic
PORTVERSION=	0.1.3
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.users.waitrose.com/~thunor/pipepanic/dload/ \
		LOCAL/ehaupt \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Pipe connecting game using libSDL

LICENSE=	GPLv2+ FAL
LICENSE_COMB=	multi
LICENSE_NAME_FAL=	Free artwork license
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_FAL=	${WRKSRC}/COPYING-ARTWORK
LICENSE_PERMS_FAL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		sdl
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
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
