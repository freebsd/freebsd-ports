# $FreeBSD$

PORTNAME=	libmatemixer
PORTVERSION=	1.22.0
CATEGORIES=	audio mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mixer library for MATE desktop

LICENSE=	LGPL21

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-null \
		--enable-oss \
		--disable-gtk-doc \
		--disable-gtk-doc-html \
		--disable-gtk-doc-pdf
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		PULSEAUDIO ALSA
OPTIONS_DEFAULT=	PULSEAUDIO
OPTIONS_SUB=		yes

PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
ALSA_CONFIGURE_ENABLE=		alsa
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib

.include <bsd.port.mk>
