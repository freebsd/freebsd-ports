# New ports collection makefile for:	thevalley
# Date created:				28 March 2004
# Whom:					Edwin Groothuis
#
# $FreeBSD$

PORTNAME=	thevalley
PORTVERSION=	0.98
CATEGORIES=	games
MASTER_SITES=	http://www.autismuk.freeserve.co.uk/
DISTNAME=	valley-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	The Valley is a rewrite of an old RPG from the early 1980s

USE_LIBTOOL_VER=13
USE_X=		yes
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_SDL=	sdl
USE_REINPLACE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

PLIST_FILES=	bin/valley

post-configure:
	${REINPLACE_CMD} \
		-e 's,^LIBTOOL =.*,LIBTOOL= $$(SHELL) ${LIBTOOL} --silent,' \
		-e 's,^transform =.*,transform = s\,^\,\,,' \
		${WRKSRC}/valley/Makefile

.include <bsd.port.mk>
