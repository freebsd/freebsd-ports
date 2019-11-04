# $FreeBSD$

PORTNAME=	dreamchess
DISTVERSION=	0.3.0
CATEGORIES=	games

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	OpenGL chess game

LICENSE=	GPLv3+ BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSE.txt
LICENSE_DISTFILES_GPLv3+ =		${DISTNAME}
LICENSE_DISTFILES_BSD2CLAUSE=		${DISTNAME}
LICENSE_DISTFILES_BSD3CLAUSE=		${DISTNAME}
LICENSE_DISTFILES_CC-BY-NC-ND-3.0=	${DISTNAME}.tar.gz

BUILD_DEPENDS=	flex:textproc/flex
LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		bison cmake gl sdl
USE_GITHUB=	yes
USE_GL=		gl glew glu
USE_SDL=	image2 mixer2

PLIST_FILES=	bin/dreamchess \
		bin/dreamer \
		man/man6/dreamchess.6.gz \
		man/man6/dreamer.6.gz \
		share/applications/dreamchess.desktop \
		share/icons/hicolor/256x256/apps/dreamchess.png \
		share/icons/hicolor/48x48/apps/dreamchess.png

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
