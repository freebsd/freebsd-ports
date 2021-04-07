PORTNAME=	chroma
PORTVERSION=	1.18
CATEGORIES=	games
MASTER_SITES=	http://www.level7.org.uk/chroma/download/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Abstract puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext localbase sdl tar:bzip2
GNU_CONFIGURE=	yes

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	INTERFACES
OPTIONS_MULTI_INTERFACES=SDL CURSES
OPTIONS_DEFAULT=SDL CURSES

SDL_DESC=	Enable SDL interface
CURSES_DESC=	Enable curses interface

OPTIONS_SUB=		yes
CURSES_USES=		ncurses
CURSES_CONFIGURE_ENABLE=curses
CURSES_PLIST_FILES=	bin/${PORTNAME}-curses
SDL_CONFIGURE_ENABLE=	sdl
SDL_LIB_DEPENDS=	libfreetype.so:print/freetype2
SDL_USE=		SDL=sdl,image
SDL_PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
