# New ports collection makefile for:	trackballs
# Date created:				21 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trackballs
PORTVERSION=	1.1.4
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/music/1.4/:music
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-music-1.4.tar.bz2:music

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LICENSE=	GPLv2

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	desktopfileutils
INSTALLS_ICONS=	yes
MAKE_ARGS=	mkinstalldirs="${MKDIR}"

MAN6=	trackballs.6
MANCOMPRESSED=	no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	NLS MUSIC
MUSIC_DESC=	Install additional music
OPTIONS_DEFAULT=	NLS MUSIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MMUSIC}
PLIST_SUB+=	MUSIC=""
.else
PLIST_SUB+=	MUSIC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|install -D|$$(INSTALL)|' \
		${WRKSRC}/share/Makefile.in

post-install:
.if ${PORT_OPTIONS:MMUSIC}
	@${INSTALL_DATA} ${WRKDIR}/trackballs-music/*.ogg ${DATADIR}/music/
.endif
	@${INSTALL_DATA} ${WRKSRC}/share/icons/${PORTNAME}-48x48.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	-@update-desktop-database

.include <bsd.port.mk>
