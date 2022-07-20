PORTNAME=	pavucontrol
PORTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK mixer for PulseAudio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libjson-glib-1.0.so:devel/json-glib \
		libpulse.so:audio/pulseaudio

USES=		compiler:c++11-lang gettext gmake gnome pkgconfig tar:xz
USE_GNOME=	glibmm gtkmm30 intltool libsigc++20
USE_CXXSTD=	c++11

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--disable-lynx

post-patch:
# Install locales files in right place
	${REINPLACE_CMD} -e 's|[$$][(]DATADIRNAME[)]|share|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
