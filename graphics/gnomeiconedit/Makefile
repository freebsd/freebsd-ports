# New ports collection makefile for:	gnomeiconedit
# Date created:				28th January 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeiconedit
PORTVERSION=	1.2.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	giconedit
DISTNAME=	gnome-iconedit-${PORTVERSION}

MAINTAINER=	josef@FreeBSD.org
COMMENT=	A small GNOME Icon Editor

USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack bonobo gnomeprint
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
