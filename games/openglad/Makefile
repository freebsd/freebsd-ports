# New ports collection makefile for:  	openglad
# Date created:       		13 May 2003
# Whom:  			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	openglad
PORTVERSION=	0.98
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	snowstorm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL port of an old DOS game called Gladiator

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"
PLIST_SUB=	DOCDIR=share/doc/${PORTNAME}

NOT_FOR_ARCHS=	sparc64

post-configure:
	${REINPLACE_CMD} -e 's|/path/to/data/dir|${LOCALBASE}/share/openglad|g' \
		${WRKSRC}/openglad.cfg

.include <bsd.port.mk>
