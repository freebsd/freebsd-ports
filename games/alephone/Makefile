# New ports collection makefile for:	alephone
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone
PORTVERSION=	0.12.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	marathon
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	malyn@strangeGizmo.com
COMMENT=	The open source version of Bungie's Marathon game

USE_SDL=	image net sdl
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-patch:
	@${PERL} -pi -e 's,^#include \"network_modem.h\".*,,' \
		${WRKSRC}/Source_Files/Network/network.cpp \
		${WRKSRC}/Source_Files/Network/network_stream.cpp \

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
