# New ports collection makefile for:	ghfaxviewer
# Date created:			Fri Apr 20 13:08:00  MET DST 2001
# Whom:				Dominik Brettnacher <domi@saargate.de>
#
# $FreeBSD$
#

PORTNAME=	ghfaxviewer
PORTVERSION=	0.22.0
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	halifax

MAINTAINER=	domi@saargate.de
COMMENT=	GNOME compliant fax viewer capable of displaying TIFF G3 faxes

LIB_DEPENDS=	gnomeprint.16:${PORTSDIR}/print/gnomeprint \
		gconf-1.1:${PORTSDIR}/devel/gconf \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	halifax.1 ghfaxviewer.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\(\$$(datadir)/\)gnome/|\1|g ; \
		 s|\$$(datadir)/locale|$$(prefix)/share/locale|g'

.include <bsd.port.mk>
