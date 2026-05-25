PORTNAME=	libmatemixer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.28.0
PORTREVISION=	2
CATEGORIES=	audio mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mixer library for MATE desktop
WWW=		https://github.com/mate-desktop/libmatemixer

LICENSE=	LGPL21

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

PORTSCOUT=	limitw:1,even

USES=		autoreconf gettext gmake gnome libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mate-desktop
USE_GNOME=	glib20 intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-null \
		--enable-oss \
		--disable-gtk-doc \
		--disable-gtk-doc-html \
		--disable-gtk-doc-pdf
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		PULSEAUDIO ALSA
OPTIONS_SUB=		yes

PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
ALSA_CONFIGURE_ENABLE=		alsa
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib

.include <bsd.port.mk>
