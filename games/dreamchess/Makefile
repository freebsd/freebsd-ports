PORTNAME=	dreamchess
DISTVERSION=	0.3.0
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL chess game
WWW=		https://www.dreamchess.org

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE.txt
LICENSE_DISTFILES_BSD2CLAUSE=		${DISTFILES:N*music*}
LICENSE_DISTFILES_BSD3CLAUSE=		${DISTFILES:N*music*}
LICENSE_DISTFILES_CC-BY-NC-ND-3.0=	${DISTFILES:M*music*:S/:music//}
LICENSE_DISTFILES_GPLv3+ =		${DISTFILES:N*music*}

BUILD_DEPENDS=	flex:textproc/flex
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		bison cmake gl sdl
USE_GITHUB=	yes
USE_GL=		gl glew glu
USE_SDL=	image2 mixer2

PLIST_FILES=	bin/dreamchess \
		bin/dreamer \
		share/applications/dreamchess.desktop \
		share/icons/hicolor/256x256/apps/dreamchess.png \
		share/icons/hicolor/48x48/apps/dreamchess.png \
		share/man/man6/dreamchess.6.gz \
		share/man/man6/dreamer.6.gz

PORTDATA=	*
PORTDOCS=	AUTHORS.txt

OPTIONS_DEFINE=		DOCS MUSIC
OPTIONS_DEFAULT=	MUSIC

MUSIC_DESC=		Install DreamChess music
MUSIC_GH_PROJECT=	${PORTNAME}-music:music
MUSIC_GH_TAGNAME=	1.0:music

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMUSIC}
LICENSE+=	CC-BY-NC-ND-3.0
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/doc/DreamChess/AUTHORS.txt ${STAGEDIR}${DOCSDIR}
	${RM} -R ${STAGEDIR}${PREFIX}/share/doc/DreamChess

post-install-DOCS-off:
	${RM} -R ${STAGEDIR}${PREFIX}/share/doc/DreamChess

post-install-MUSIC-on:
	cd ${WRKDIR}/${PORTNAME}-music-${MUSIC_GH_TAGNAME:S/:music//}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
