# Ports collection Makefile for:	glunarclock
# Date created:				31 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glunarclock
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	astro gnome
MASTER_SITES=	http://www.fortunecity.de/naturpark/bienen/99/download/

MAINTAINER=	sobomax@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
			 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
