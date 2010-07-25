# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/audio/gnome-media/Makefile,v 1.2 2010/06/25 06:51:09 kwm Exp $
#

PORTNAME=	gnome-media
PORTVERSION=	2.30.0
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 2 desktop

BUILD_DEPENDS=	xml2po:${PORTSDIR}/textproc/gnome-doc-utils
LIB_DEPENDS=	canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 libxml2 gconf2
USE_GSTREAMER=	gconf good
CONFIGURE_ARGS=	--disable-gstmix
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-audio-profiles.schemas \
		gnome-sound-recorder.schemas

OPTIONS=	PULSEAUDIO "Enable Pulse Audio support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulseaudio
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulseaudio
PLIST_SUB+=	PULSE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|have_gladeui=true|have_gladeui=false|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
