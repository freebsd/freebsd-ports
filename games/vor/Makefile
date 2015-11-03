# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vor
PORTVERSION=	0.5.5
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://qualdan.com/vor/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Dodge the rocks until you die

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2 gmake
USE_SDL=	mixer image sdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Variations on Rockdodger" \
		"Dodge the rocks until you die" \
		"${DATADIR}/icon.png" \
		"vor" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
