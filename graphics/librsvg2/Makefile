# New ports collection makefile for:    librsvg
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsvg
PORTVERSION=	1.0.2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/librsvg

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	freetype.8:${PORTSDIR}/print/freetype2 \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		xml.5:${PORTSDIR}/textproc/libxml \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMELIBS=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
