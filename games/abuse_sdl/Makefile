# New ports collection makefile for:	abuse_sdl
# Date created:				11 May 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	abuse_sdl
PORTVERSION=	0.7.1
CATEGORIES=	games
MASTER_SITES=	http://abuse.zoy.org/raw/Downloads/ \
		http://epix.linux.tucows.com/files/ \
		http://blueyonder.linux.tucows.com/files/ \
		http://casemanl.linux.tucows.com/files/
DISTNAME=	abuse-${PORTVERSION}

MAINTAINER=	chris@officialunix.com
COMMENT=	An SDL port of the Abuse game engine

# Add in the oposite, request games/abuse if being installed directly
# Instead of games/abuse
RUN_DEPENS=	abuse:${PORTSDIR}/games/abuse

USE_GL=		gl
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${DISTNAME}

MAN6=		abuse.6

PLIST_FILES=	bin/abuse.sdl \
		share/abuse_sdl/abuse.bmp \
		share/abuse_sdl/abuse.lsp \
		share/abuse_sdl/abuse.png

PLIST_DIRS=	share/abuse_sdl

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
