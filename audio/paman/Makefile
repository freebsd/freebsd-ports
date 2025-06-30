PORTNAME=	paman
PORTVERSION=	0.9.4
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Gtk frontend for PulseAudio
WWW=		https://0pointer.de/lennart/projects/paman/

LIB_DEPENDS=	libglademm-2.4.so:devel/libglademm24 \
		libpulse.so:audio/pulseaudio

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gmake pathfix pkgconfig
USE_CXXSTD=	c++11

CONFIGURE_ARGS=	--disable-lynx

.include <bsd.port.mk>
