# New ports collection makefile for:	bugbuddy2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugbuddy2
PORTVERSION=	2.2.102
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/bug-buddy/2.2
DISTNAME=	bug-buddy-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnome-desktop-2.3:${PORTSDIR}/x11/gnomedesktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=	bug-buddy.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
