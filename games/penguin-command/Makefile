# New ports collection makefile for:	penguin-command
# Date created:			Apr 4, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	penguin-command
PORTVERSION=	1.6.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A clone of the classic game Missile Command

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_SDL=	mixer sdl
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_TARGET=
MAN6=		penguin-command.6 penguin-command.ja.6

post-patch:
	${REINPLACE_CMD} 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g' \
		${WRKSRC}/configure ${WRKSRC}/src/*.[ch]
	${REINPLACE_CMD} 's/ -lz -lSDL -lm/ -lz -lm/g' ${WRKSRC}/configure

.include <bsd.port.mk>
