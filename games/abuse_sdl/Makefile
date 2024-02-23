PORTNAME=	abuse_sdl
PORTVERSION=	0.8
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	GENTOO \
		http://abuse.zoy.org/raw-attachment/wiki/download/
DISTNAME=	abuse-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL port of the Abuse game engine
WWW=		http://abuse.zoy.org/

LICENSE=	GPLv2+ PD WTFPL BPRINCE
LICENSE_COMB=	multi
LICENSE_NAME_BPRINCE=	Boby Prince permission for Debian to redistribute music/sfx files
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_WTFPL=	${WRKSRC}/COPYING.WTFPL
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS_BPRINCE=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		cpe gl localbase:ldflags pathfix sdl
CPE_VENDOR=	abuse
CPE_PRODUCT=	abuse-sdl
USE_CXXSTD=	c++14
USE_GL=		gl
USE_SDL=	mixer sdl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-assetdir=${DATADIR} --enable-release

DESKTOP_ENTRIES="Abuse-SDL" "" "abuse" \
		"abuse" "Game;StrategyGame;" ""

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/abuse.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
