# Ports collection Makefile for:        bulb
# Date created:                         03/09/2000
# Whom:                                 smoberly@xavier.dyndns.org
#
# $FreeBSD$
#

PORTNAME=	bulb
PORTVERSION=	1.0.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.idiap.ch/~gobry/bulb/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.mk>
