# New ports collection makefile for:	gtktetcolor
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtktetcolor
PORTVERSION=	0.5.0
CATEGORIES=	games gnome
MASTER_SITES=	ftp://canopus.iacp.dvo.ru/pub/Games/gtktetcolor/ \
		http://www.dvgu.ru/ifit/~panov/gtktetcolor/ \
		http://metalab.unc.edu/pub/Linux/games/

MAINTAINER=	sobomax@FreeBSD.org

USE_BZIP2=	yes
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
