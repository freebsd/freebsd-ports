PORTNAME=	libspice-server
DISTVERSION=	0.15.0
CATEGORIES=	devel
MASTER_SITES=	https://www.spice-space.org/download/releases/spice-server/
DISTNAME=	spice-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Implements the server side of the SPICE protocol

LICENSE=	GPLv2

LIB_DEPENDS=	libopus.so:audio/opus
BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive \
		spice-protocol>=0.12.10:devel/spice-protocol

OPTIONS_DEFINE=		GSTREAMER LZ4 SASL STATISTICS
OPTIONS_DEFAULT=	GSTREAMER LZ4 SASL
STATISTICS_DESC=	Statistic code

GSTREAMER_USES=			gstreamer
GSTREAMER_CONFIGURE_ON=		--enable-gstreamer=1.0
GSTREAMER_CONFIGURE_OFF=	--enable-gstreamer=no
GSTREAMER_LIB_DEPENDS=		liborc-0.4.so:devel/orc

LZ4_CONFIGURE_ENABLE=	lz4
LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4

SASL_CONFIGURE_WITH=	sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

STATISTICS_CONFIGURE_ENABLE=	statistics

USES=		autoreconf:2.69 compiler:c++11-lang cpe gmake gnome jpeg \
		libtool localbase:ldflag pkgconfig python ssl tar:bzip2 xorg

USE_GNOME=	glib20
USE_XORG=	pixman
USE_LDCONFIG=	yes

CPE_VENDOR=	spice_project
CPE_PRODUCT=	spice

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-celt051 \
		--enable-manual=no

SPICE_SSL_CFLAGS=	-I${OPENSSLINC}
SPICE_SSL_LIBS=	-L${OPENSSLLIB} -lcrypto -lssl
CONFIGURE_ENV+=	SSL_CFLAGS="${SPICE_SSL_CFLAGS}" SSL_LIBS="${SPICE_SSL_LIBS}" \
		OPENSSL_CFLAGS="${SPICE_SSL_CFLAGS}" OPENSSL_LIBS="${SPICE_SSL_LIBS}" \
		PYTHON=${PYTHON_CMD}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
