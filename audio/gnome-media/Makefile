# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomemedia2
PORTVERSION=	2.4.1.1
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-media/2.4
DISTNAME=	gnome-media-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 2 desktop

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox
LIB_DEPENDS=	gstplay-0.6.1:${PORTSDIR}/multimedia/gstreamer-plugins

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomedesktop gail
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]CDROM_HOST[)]|freebsd|g' \
		${WRKSRC}/gnome-cd/Makefile.in

.include <bsd.port.mk>
