# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/gnome-media/Makefile,v 1.130 2009/03/17 22:20:16 kwm Exp $
#

PORTNAME=	gnome-media
PORTVERSION=	2.26.0
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 2 desktop

LIB_DEPENDS=	pulse.0:${PORTSDIR}/audio/pulseaudio \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop
USE_GSTREAMER=	cdparanoia esound gconf good
CONFIGURE_ARGS=	--enable-ipv6
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-audio-profiles.schemas \
		gnome-sound-recorder.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]CDROM_HOST[)]|freebsd|g' \
		${WRKSRC}/gnome-cd/Makefile.in
	@${REINPLACE_CMD} -e 's|acd0c|acd0|g ; s|== "xyes|= "xyes|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
