# New ports collection makefile for:	tuxkart
# Date created:				08 Jun 2001
# Whom:					Alexander Langer <alex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tuxkart
PORTVERSION=	0.4.0
CATEGORIES=	games
MASTER_SITES=	http://tuxkart.sourceforge.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL action kart racing game

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USE_X_PREFIX=	yes
USE_GL=		yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lusbhid"
CONFIGURE_ARGS=	--with-plib=${X11BASE}

post-patch:
	@${REINPLACE_CMD} -e 's|-O6|${PTHREAD_CFLAGS}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|datadir/games|datadir|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[\$$][(]prefix[)]/games|@bindir@|g ; \
		 s|[\$$][(]datadir[)]/games|\$$(datadir)|g'

.include <bsd.port.mk>
