# New ports collection makefile for:	alephone
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone
PORTVERSION=	20050118
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	marathon
DISTNAME=	AlephOne-${PORTVERSION}

MAINTAINER=	malyn@strangeGizmo.com
COMMENT=	The open source version of Bungie's Marathon game

USE_SDL=	image net sdl sound
USE_GL=		yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CFLAGS="${CFLAGS} -I${X11BASE}/include" \
		CXXFLAGS="${CXXFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib"
CONFIGURE_ARGS+=--program-transform-name=""

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500035
	@${REINPLACE_CMD} -e 's|streambuf>|streambuf\.h>|' \
		${WRKSRC}/Source_Files/CSeries/snprintf.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
