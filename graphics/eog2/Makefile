# New ports collection makefile for:	eog2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eog2
PORTVERSION=	1.0.4
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/1.0
DISTNAME=	eog-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		gnomeprint-2.0:${PORTSDIR}/print/libgnomeprint \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
