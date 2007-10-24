# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/gnome-media/Makefile,v 1.112 2007/09/19 12:22:57 ahze Exp $
#

PORTNAME=	gnome-media
PORTVERSION=	2.20.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-media/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 2 desktop

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop \
		gail nautiluscdburner
USE_GSTREAMER=	cdparanoia esound gconf good
CONFIGURE_ARGS=	--enable-ipv6
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	CDDB-Slave2.schemas gnome-audio-profiles.schemas \
		gnome-cd.schemas gnome-sound-recorder.schemas \
		gnome-volume-control.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]CDROM_HOST[)]|freebsd|g' \
		${WRKSRC}/gnome-cd/Makefile.in
	@${REINPLACE_CMD} -e 's|acd0c|acd0|g ; s|== "xyes|= "xyes|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
