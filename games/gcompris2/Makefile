# New ports collection makefile for:	gcompris2
# Date created:				23 April 2003
# Whom:					Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gcompris2
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gcompris
DISTNAME=	gcompris-${PORTVERSION}

MAINTAINER=	gnome@freebsd.org
COMMENT=	A simple Gnome2-based education game for children starting at 3

LIB_DEPENDS=	vorbis.2:${PORTSDIR}/audio/libvorbis \
		ao.3:${PORTSDIR}/audio/libao

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_GNOME=      gnomehack gnomeprefix libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
