# New ports collection makefile for:	tux-aqfh
# Date created:				10 Jun 2001
# Whom:					Alexander Langer <alex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tux_aqfh
PORTVERSION=	1.0.14
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://tuxaqfh.sourceforge.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL adventure game

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-plib=${X11BASE}

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lusbhid ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lplibsl -lplibssg|-lplibsl -lplibjs -lplibssg|g ; \
		 s|-O6||g ; \
		 s|-lpthread||g ; \
		 s|datadir/games|datadir|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/games|@bindir@|g ; \
		 s|$$(datadir)/games|$$(datadir)|g'

.include <bsd.port.mk>
