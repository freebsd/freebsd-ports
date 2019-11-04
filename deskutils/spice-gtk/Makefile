# Created by: olevole@olevole.ru
# $FreeBSD$

PORTNAME=	spice-gtk
PORTVERSION=	0.37
CATEGORIES?=	deskutils gnome
MASTER_SITES=	http://www.spice-space.org/download/gtk/

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	Gtk client and libraries for SPICE remote desktop servers

LICENSE=	GPLv2

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libjson-glib-1.0.so:devel/json-glib \
		libopus.so:audio/opus \
		libva-x11.so:multimedia/libva
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${PY_FLAVOR} \
		spice-protocol>=0.12.15:devel/spice-protocol
RUN_DEPENDS=	spice-protocol>=0.12.15:devel/spice-protocol

USES=		autoreconf compiler:c11 cpe gettext-tools gmake gnome jpeg \
		libtool localbase:ldflags pkgconfig python ssl tar:bzip2 xorg
USE_XORG=	pixman x11
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix gtk30 intltool introspection:build
USE_GSTREAMER1=	yes

CPE_VENDOR=	redhat

SPICE_SSL_CFLAGS=	-I${OPENSSLINC}
SPICE_SSL_LIBS=		-L${OPENSSLLIB} -lcrypto -lssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="${SPICE_SSL_CFLAGS}" \
			OPENSSL_LIBS="${SPICE_SSL_LIBS}"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# we can't use pathfix with USES=autoreconf
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		BUILTIN-MJPEG DOCS INTROSPECTION LZ4 NLS PIE POLKIT \
			PULSEAUDIO SASL
OPTIONS_DEFAULT=	BUILTIN-MJPEG INTROSPECTION LZ4 PIE POLKIT PULSEAUDIO \
			SASL
OPTIONS_SUB=		yes

LZ4_CONFIGURE_ON=	--enable-lz4=yes
LZ4_CONFIGURE_OFF=	--enable-lz4=no
LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

BUILTIN-MJPEG_CONFIGURE_ENABLE=	builtin-mjpeg
BUILTIN-MJPEG_DESC=		Enable the builtin mjpeg video decoder

INTROSPECTION_CONFIGURE_ON=	--enable-introspection=yes
INTROSPECTION_CONFIGURE_OFF=	--enable-introspection=no
INTROSPECTION_DESC=		Enable introspection for this build

PIE_CONFIGURE_ON=	--enable-pie=yes
PIE_CONFIGURE_OFF=	--enable-pie=no
PIE_DESC=		Enable position-independent-executable support (for usb acl helper)

POLKIT_CONFIGURE_ON=	--enable-polkit=yes
POLKIT_CONFIGURE_OFF=	--enable-polkit=no
POLKIT_DESC=		Enable PolicyKit support (for usb acl helper)

PULSEAUDIO_CONFIGURE_ON=	--enable-pulse=yes
PULSEAUDIO_CONFIGURE_OFF=	--enable-pulse=no
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

SASL_CONFIGURE_ON=	--with-sasl=yes
SASL_CONFIGURE_OFF=	--with-sasl=no
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

.include <bsd.port.mk>
