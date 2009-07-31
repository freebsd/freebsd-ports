# New ports collection makefile for: cosmosmash
# Date created:                      12 Apr 2008
# Whom:                              Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	cosmosmash
DISTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A clone of the Intellivision(TM) game Astrosmash(TM)

LIB_DEPENDS=	flatzebra:${PORTSDIR}/devel/flatzebra \
		aa:${PORTSDIR}/graphics/aalib \
		mikmod:${PORTSDIR}/audio/libmikmod \
		audiofile:${PORTSDIR}/audio/libaudiofile

USE_SDL=	sdl image mixer
USE_XORG=	x11 xau xdmcp
USE_ICONV=	yes
USE_GNOME=	desktopfileutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `${SDL_CONFIG} --cflags`" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} `${SDL_CONFIG} --libs`"

MAN6=	cosmosmash.6

post-patch:
	@${REINPLACE_CMD} 's|^pkgsounddir = .*|pkgsounddir = ${DATADIR}/sounds|' ${WRKSRC}/src/Makefile.in
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} 's|^docdir = .*|docdir = ${DOCSDIR}|' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} 's|^install-data-am: .*|install-data-am: install-man|'	${WRKSRC}/Makefile.in
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
