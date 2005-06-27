# New ports collection makefile for:	kobodeluxe
# Date created:		12 June 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	kobodeluxe
DISTVERSION=	0.4pre10
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/
DISTNAME=	KoboDeluxe-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SDL port of the scrolling game XKobo

USE_SDL=	image sdl
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN6=		kobodl.6

SCOREDIR=	/var/games/${PORTNAME}
PLIST_SUB=	SCOREDIR="${SCOREDIR}"

OPTIONS=	OPENGL "OpenGL rendering layer (experimental)" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

.if defined(WITH_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=	--enable-opengl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/games/kobo-deluxe|${DATADIR}|; \
		s|$$(prefix)/games/kobo-deluxe/scores|${SCOREDIR}|; \
		s|-lSDL$$||; s|SDL/SDL|SDL|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(datadir)/games/kobo-deluxe|${DATADIR}|' \
		${WRKSRC}/data/Makefile.in

post-install:
	${CHGRP} games ${PREFIX}/bin/kobodl
	${CHMOD} g+s ${PREFIX}/bin/kobodl
	${INSTALL} -d -o root -g games -m 775 ${SCOREDIR}

.include <bsd.port.post.mk>
