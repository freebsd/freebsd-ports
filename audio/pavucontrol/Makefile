PORTNAME=	pavucontrol
PORTVERSION=	6.1
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK mixer for PulseAudio
WWW=		https://freedesktop.org/software/pulseaudio/pavucontrol/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpulse.so:audio/pulseaudio

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	gtkmm40 intltool
MESON_ARGS=	-Dlynx=false

.include <bsd.port.mk>
