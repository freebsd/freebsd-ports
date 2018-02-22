# Created by: olevole@olevole.ru
# $FreeBSD$

PORTNAME=	spice-gtk
PORTVERSION=	0.34
CATEGORIES?=	deskutils gnome
MASTER_SITES=	http://www.spice-space.org/download/gtk/

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	Gtk client and libraries for SPICE remote desktop servers

LICENSE=	GPLv2

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libopus.so:audio/opus
BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${PY_FLAVOR}
RUN_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol

USES=		autoreconf cpe gmake jpeg libtool pkgconfig tar:bzip2 \
		python ssl localbase:ldflags
USE_XORG=	x11 pixman
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix gtk30 intltool introspection:build
CPE_VENDOR=	redhat

SPICE_SSL_CFLAGS=	-I${OPENSSLINC}
SPICE_SSL_LIBS=	-L${OPENSSLLIB} -lcrypto -lssl
CONFIGURE_ENV+=	SSL_CFLAGS="${SPICE_SSL_CFLAGS}" SSL_LIBS="${SPICE_SSL_LIBS}" \
		OPENSSL_CFLAGS="${SPICE_SSL_CFLAGS}" OPENSSL_LIBS="${SPICE_SSL_LIBS}"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# we can't use pathfix with USES=autoreconf
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	LZ4 NLS DOCS SASL
OPTIONS_DEFAULT=	GSTREAMER LZ4 PULSEAUDIO SASL

OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	GSTREAMER PULSEAUDIO

OPTIONS_SUB=	yes

LZ4_CONFIGURE_ENABLE=	lz4
LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

NOAUDIO_DESC=		Disable audio backend

GSTREAMER_CONFIGURE_ENABLE=	gstaudio
GSTREAMER_USE=			GSTREAMER1=yes
GSTREAMER_CONFIGURE_ON=		--enable-gstvideo=yes
GSTREAMER_CONFIGURE_OFF=	--enable-gstvideo=no

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

SASL_CONFIGURE_WITH=		sasl=yes
SASL_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2

.include <bsd.port.mk>
