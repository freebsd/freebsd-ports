# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	vor
PORTVERSION=	0.5.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://qualdan.com/vor/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Dodge the rocks until you die

USES=		gmake
USE_SDL=	mixer image sdl
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
