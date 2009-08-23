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
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 libgnomeui
USE_GSTREAMER=	gconf good
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-audio-profiles.schemas \
		gnome-sound-recorder.schemas

OPTIONS=	ESOUND "Enable the EsounD module" on \
		IPV6 "Enable support for IPv6" on \
		PULSEAUDIO "Enable the PulseAudio module" on

.include <bsd.port.pre.mk>

.if defined(WITH_ESOUND)
USE_GSTREAMER+=	esound
PLIST_SUB+=	VUMETER=""
.else
CONFIGURE_ARGS+=--disable-esound --disable-esdtest
PLIST_SUB+=	VUMETER="@comment "
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--disable-pulse
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]CDROM_HOST[)]|freebsd|g' \
		${WRKSRC}/gnome-cd/Makefile.in
	@${REINPLACE_CMD} -e 's|acd0c|acd0|g ; s|== "xyes|= "xyes|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
