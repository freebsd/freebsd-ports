# New ports collection makefile for:	tux-aqfh
# Date created:				10 Jun 2001
# Whom:					Alexander Langer <alex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tux_aqfh
PORTVERSION=	1.0.14
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://tuxaqfh.sourceforge.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL adventure game

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-plib=${X11BASE}

post-patch:
	@${REINPLACE_CMD} -e 's|-O6|${PTHREAD_CFLAGS}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|datadir/games|datadir|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[\$$][(]prefix[)]/games|\@bindir\@|g ; \
		 s|[\$$][(]datadir[)]/games|\$$(datadir)|g'

.include <bsd.port.mk>
