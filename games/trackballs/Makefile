# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trackballs
PORTVERSION=	1.1.4
PORTREVISION=	20
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/music/1.4/:music
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-music-1.4.tar.bz2:music

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LICENSE=	GPLv2

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
USES=		gmake gettext desktop-file-utils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
MAKE_ARGS=	mkinstalldirs="${MKDIR}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	MUSIC NLS
OPTIONS_DEFAULT=	MUSIC NLS
OPTIONS_SUB=	yes
MUSIC_DESC=	Install additional music
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|install -D|$$(INSTALL)|' \
		${WRKSRC}/share/Makefile.in

post-install:
.if ${PORT_OPTIONS:MMUSIC}
	${INSTALL_DATA} ${WRKDIR}/trackballs-music/*.ogg ${STAGEDIR}${DATADIR}/music/
.endif
	${INSTALL_DATA} ${WRKSRC}/share/icons/${PORTNAME}-48x48.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
