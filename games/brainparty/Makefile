PORTNAME=	brainparty
PORTVERSION=	0.61
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://launchpad.net/brainparty/trunk/${PORTVERSION}/+download/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Family-friendly set of 36 puzzle games

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler gl gmake sdl
USE_SDL=	sdl mixer ttf gfx image
USE_GL=		gl glu

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|Content/|${DATADIR}/|' ${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Content/* ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
