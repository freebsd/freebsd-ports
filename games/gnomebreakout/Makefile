# New ports collection makefile for:	gnomebreakout
# Date created:				01 Sep 2000
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebreakout
PORTVERSION=	0.5.2
CATEGORIES=	games gnome
MASTER_SITES=	http://www.senet.com.au/~alcaron/
DISTNAME=	gnome-breakout-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
