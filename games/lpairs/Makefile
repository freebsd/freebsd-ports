PORTNAME=	lpairs
PORTVERSION=	1.0.5
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Classical memory game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl

PORTDATA=	*

DESKTOP_ENTRIES="LPairs" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|games/lpairs|lpairs|' ${WRKSRC}/configure.in
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e 's|-Wno-unused-result||' ${WRKSRC}/configure.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.post.mk>
