# New ports collection makefile for:	gThumb2
# Date created:				17 Aug 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gthumb2
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.1
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	verbophobe@hotmail.com
COMMENT=	An image viewer and browser for the GNOME 2 environment

LIB_DEPENDS=	gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui \
		gnomeprintui-2-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gthumb.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
