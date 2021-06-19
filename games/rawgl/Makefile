# Created by: Piotr Kubaj <pkubaj@FreeBSD.org>

PORTNAME=	rawgl
PORTVERSION=	g20180321
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Another World engine reimplementation

LICENSE=	NONE

USE_GITHUB=	yes
GH_ACCOUNT=	cyxx
GH_TAGNAME=	b6dd795

USES=		gl sdl
USE_GL=		gl
USE_SDL=	mixer2 sdl2
ALL_TARGET=	rawgl

SUB_FILES=	pkg-message rawgl
SUB_LIST=	DATADIR=${DATADIR}

PLIST_FILES=	bin/${PORTNAME} libexec/${PORTNAME} '@dir %%DATADIR%%'
PORTDOCS=	*

DESKTOP_ENTRIES="raw(gl)" \
		"" \
		"" \
		rawgl \
		"Game;ActionGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|MIX_INIT_FLUIDSYNTH|MIX_INIT_MID|' ${WRKSRC}/mixer.cpp

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
