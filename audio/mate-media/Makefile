# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-media
PORTVERSION=	1.6.0
CATEGORIES=	audio mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the MATE desktop

LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils intlhack ltverhack \
		panel
USE_GNOME=	gnomehier glib20 gnomehier gtk20 libxml2
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-pulseaudio \
		--enable-gst-mixer-applet
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.panel.applet.mixer.gschema.xml \
		org.mate.volume-control.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|mixer_applet2|mate_mixer_applet2|g' \
		${WRKSRC}/gst-mixer-applet/Makefile.am \
		${WRKSRC}/gst-mixer-applet/load.c \
		${WRKSRC}/gst-mixer-applet/org.mate.panel.applet.MixerAppletFactory.service.in \
		${WRKSRC}/gst-mixer-applet/org.mate.applets.MixerApplet.mate-panel-applet.in.in

.include <bsd.port.mk>
