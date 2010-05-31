# New ports collection makefile for:	chroma
# Date created:		28 Jan 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chroma
PORTVERSION=	1.08
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.level7.org.uk/chroma/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Abstract puzzle game

USE_BZIP2=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" LIBS="-lintl" \
		CPPFLAGS="-I${LOCALBASE}/include"

PORTDOCS=	README

OPTIONS=	SDL	"Enable SDL interface"	on \
		CURSES	"Enable curses interface" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_CURSES)
CONFIGURE_ARGS+=--disable-curses
PLIST_SUB+=	CURSES="@comment "
.else
PLIST_SUB+=	CURSES=""
.endif

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=--disable-sdl
PLIST_SUB+=	SDL="@comment "
.else
USE_SDL=	sdl image
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
PLIST_SUB+=	SDL=""
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
