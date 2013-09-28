# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chroma
PORTVERSION=	1.08
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.level7.org.uk/chroma/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Abstract puzzle game

USE_BZIP2=	yes
USES=		gettext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lintl"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README
PORTDATA=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	INTERFACES
OPTIONS_MULTI_INTERFACES=	SDL CURSES
OPTIONS_DEFAULT=SDL CURSES

SDL_DESC=	Enable SDL interface
CURSES_DESC=	Enable curses interface

OPTIONS_SUB=	yes
CURSES_USES=	ncurses
CURSES_CONFIGURE_ENABLE=curses
SDL_CONFIGURE_ENABLE=	sdl
SDL_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl image
PLIST_FILES+=	bin/${PORTNAME}
.endif

.if ${PORT_OPTIONS:MCURSES}
PLIST_FILES+=	bin/${PORTNAME}-curses
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
