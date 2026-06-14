PORTNAME=	lmarbles
DISTVERSION=	1.1.1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Atomix-like game of moving marbles in puzzles
WWW=		http://lgames.sourceforge.net/index.php?project=LMarbles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime gmake localbase:ldflags sdl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes

LDFLAGS+=	-lintl

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/icons/hicolor/256x256/apps|(datadir)/pixmaps|' \
		${WRKSRC}/Makefile.in

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog README README-SDL.txt" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
