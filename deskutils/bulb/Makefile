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
COMMENT=	GNOME applet to warn about task terminations

USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs gnomeprefix libpanel
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		's|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.mk>
