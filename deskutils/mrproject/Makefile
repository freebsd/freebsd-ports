# New ports collection makefile for:	MrProject
# Date created:				15 July 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrproject
PORTVERSION=	0.9
CATEGORIES=	deskutils gnome
MASTER_SITES=	ftp://ftp.codefactory.se/pub/software/mrproject/source/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Project management application for Gnome 2

LIB_DEPENDS=	mrproject.0:${PORTSDIR}/deskutils/libmrproject \
		gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui \
		gnomeprintui-2-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
