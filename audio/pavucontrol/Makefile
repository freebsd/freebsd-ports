# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	pavucontrol
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK mixer for PulseAudio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig gettext tar:xz compiler:c++11-lang
USE_GNOME=	glibmm intltool libsigc++20
USE_CXXSTD=	c++11

OPTIONS_SUB=	yes
OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

CONFIGURE_ARGS=	--disable-lynx

GTK2_USE=	GNOME=gtkmm24
GTK2_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
GTK2_CONFIGURE_ON=	--disable-gtk3

GTK3_USE=	GNOME=gtkmm30
GTK3_LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3

post-patch:
# Install locales files in right place
	${REINPLACE_CMD} -e 's|[$$][(]DATADIRNAME[)]|share|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
