# New ports collection makefile for:	xpilot-ng
# Date created:			11 Sep 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		xpilot-ng
PORTVERSION=		4.6.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xpilot

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		An enhanced version of XPilot

LIB_DEPENDS=		expat:${PORTSDIR}/textproc/expat2

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes

MAN6=			xpilot-ng-replay.6 \
			xpilot-ng-sdl.6 \
			xpilot-ng-server.6 \
			xpilot-ng-x11.6

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=		--program-prefix=""

OPTIONS=		SDL "SDL/OpenGL client" on

.include <bsd.port.pre.mk>

.if defined(WITH_SDL)
USE_SDL=		image sdl ttf
CONFIGURE_ARGS+=	--enable-sdl-client
PLIST_SUB+=		WITH_SDL=""
USE_GCC=		3.2
.else
PLIST_SUB+=		WITH_SDL="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,#include "SDL/,#include "SDL11/,g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
