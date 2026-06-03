PORTNAME=	libmatemixer
DISTVERSION=	1.28.0
PORTREVISION=	3
CATEGORIES=	audio mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mixer library for MATE desktop
WWW=		https://github.com/mate-desktop/libmatemixer

LICENSE=	LGPL21

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pkgconfig tar:xz
USE_GITHUB=	nodefault
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
