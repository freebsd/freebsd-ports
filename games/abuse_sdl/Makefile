# Created by: Dag-Erling C. Smørgrav <des@FreeBSD.org>

PORTNAME=	abuse_sdl
PORTVERSION=	0.8
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	GENTOO \
		http://abuse.zoy.org/raw-attachment/wiki/download/
DISTNAME=	abuse-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL port of the Abuse game engine

LICENSE=	GPLv2+ PD WTFPL BPRINCE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_WTFPL=	${WRKSRC}/COPYING.WTFPL
LICENSE_NAME_BPRINCE=	Boby Prince permission for Debian to redistribute music/sfx files
LICENSE_PERMS_BPRINCE=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		gl localbase:ldflags pathfix sdl
USE_GL=		gl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-assetdir=${DATADIR} --enable-release

PORTDOCS=	AUTHORS ChangeLog NEWS README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Abuse-SDL" "" "abuse" \
		"abuse" "Game;StrategyGame;" ""

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/abuse.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
