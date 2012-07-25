# New ports collection makefile for:	gnomeiconedit
# Date created:				28th January 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeiconedit
PORTVERSION=	1.2.0
PORTREVISION=	10
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/giconedit/giconedit-${PORTVERSION}/tar.gz
DISTNAME=	gnome-iconedit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small GNOME icon editor

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_GNOME=	gnomeprefix gnomehack bonobo gnomeprint
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
