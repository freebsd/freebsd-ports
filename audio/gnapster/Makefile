# New ports collection makefile for:	gnapster
# Date created:		24 December 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnapster
PORTVERSION=	1.4.1a
CATEGORIES=	audio
MASTER_SITES=	http://www.faradic.net/~jasta/files/

MAINTAINER=	cpiazza@FreeBSD.org

.if defined(HAVE_GNOME)
LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk_pixbuf
.endif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
WANT_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.if !defined(HAVE_GNOME)
CONFIGURE_ARGS+=--disable-gnome --disable-gdk-pixbuf
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
