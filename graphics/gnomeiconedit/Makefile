# New ports collection makefile for:	gnomeiconedit
# Date created:				28th January 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeiconedit
PORTVERSION=	1.2.0
PORTREVISION=	7
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/giconedit
DISTNAME=	gnome-iconedit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small GNOME Icon Editor

USE_GNOME=	gnomeprefix gnomehack bonobo gnomeprint
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
