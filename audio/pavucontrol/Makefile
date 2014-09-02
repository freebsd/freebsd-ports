# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD: head/audio/pavucontrol/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	pavucontrol
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK mixer for PulseAudio

LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libgtkmm-3.0.so:${PORTSDIR}/x11-toolkits/gtkmm30
RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	intltool

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
