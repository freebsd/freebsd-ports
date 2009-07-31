# New ports collection makefile for:	ghfaxviewer
# Date created:			Fri Apr 20 13:08:00  MET DST 2001
# Whom:				Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

PORTNAME=	ghfaxviewer
PORTVERSION=	0.22.0
PORTREVISION=	10
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	halifax

MAINTAINER=	domi@nonsensss.de
COMMENT=	GNOME compliant fax viewer capable of displaying TIFF G3 faxes

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gconf gnomeprint
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	halifax.1 ghfaxviewer.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
