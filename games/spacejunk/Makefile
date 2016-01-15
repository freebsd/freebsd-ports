# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spacejunk
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Video game about traveling in 2D planetary systems

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	Doesn't compile on sparc64

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

SUB_FILES=	spacejunk

PLIST_FILES=	bin/${PORTNAME} libexec/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Spacejunk" \
		"Collect garbage by navigating through the gravitational fields of planets and stars" \
		"${DATADIR}/data/art/spacejunk_icon.png" \
		"spacejunk" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/gem-uta.c \
		${WRKSRC}/libinfo/gem-uta.c
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/&|' ${WRKSRC}/src/*.c*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/spacejunk ${STAGEDIR}${PREFIX}/libexec/
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'data config.txt' ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/spacejunk ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	${RMDIR} ${STAGEDIR}${DOCSDIR}/web/templates ${STAGEDIR}${DOCSDIR}/web/toolbars

.include <bsd.port.mk>
