# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trackballs
PORTVERSION=	1.1.4
PORTREVISION=	21
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/music/1.4/:music
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-music-1.4.tar.bz2:music

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	SDL-based Marble Madness clone

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libguile.so:lang/guile
RUN_DEPENDS=	bash:shells/bash

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
USES=		gmake gettext desktop-file-utils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
MAKE_ARGS=	mkinstalldirs="${MKDIR}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	MUSIC NLS
OPTIONS_DEFAULT=	MUSIC
OPTIONS_SUB=	yes
MUSIC_DESC=	Install additional music
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|install -D|$$(INSTALL)|' \
		${WRKSRC}/share/Makefile.in

post-install-MUSIC-on:
	${INSTALL_DATA} ${WRKDIR}/trackballs-music/*.ogg ${STAGEDIR}${DATADIR}/music/

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/icons/${PORTNAME}-48x48.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
