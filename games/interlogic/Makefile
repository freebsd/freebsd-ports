# New ports collection makefile for:	interlogic
# Date created:		01 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	interlogic
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	interlogic
DISTNAME=	interLOGIC-src-${PORTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Move colored balls through the maze connecting it with each other

USE_SDL=	image sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LDFLAGS="`${SDL_CONFIG} --libs`"

WRKSRC=	${WRKDIR}/interlogic

PLIST_FILES=	bin/interlogic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/interlogic ${PREFIX}/bin/

.include <bsd.port.mk>
