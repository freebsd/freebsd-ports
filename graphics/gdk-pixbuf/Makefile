# New ports collection makefile for:	gdk-pixbuf
# Date created:		5th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gdk-pixbuf

MAINTAINER=	ade@FreeBSD.org

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMELIBS=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(datadir\)/gnome/|\$$\(datadir\)/|g ; \
		 s|\$$\(datadir\)/aclocal|\$$\(prefix\)/share/aclocal|g'

.include <bsd.port.mk>
