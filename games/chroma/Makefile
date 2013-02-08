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
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lintl"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README

OPTIONS_DEFINE=	SDL CURSES DOCS
OPTIONS_DEFAULT=SDL CURSES
SDL_DESC=	Enable SDL interface
CURSES_DESC=	Enable curses interface

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURSES}
PLIST_SUB+=	CURSES=""
.else
CONFIGURE_ARGS+=--disable-curses
PLIST_SUB+=	CURSES="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl image
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
