PORTNAME=	libspice-server
DISTVERSION=	0.15.2
CATEGORIES=	devel
MASTER_SITES=	https://www.spice-space.org/download/releases/spice-server/
DISTNAME=	spice-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Implements the server side of the SPICE protocol
WWW=		https://spice-space.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR} \
		spice-protocol>=0.12.10:devel/spice-protocol
LIB_DEPENDS=	libopus.so:audio/opus

USES=		compiler:c++11-lang cpe gmake gnome jpeg libtool \
		localbase:ldflag meson pkgconfig python ssl tar:bzip2 xorg
CPE_VENDOR=	spice_project
CPE_PRODUCT=	spice
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_XORG=	pixman

MESON_ARGS+=	-Dsmartcard=disabled

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		GSTREAMER LZ4 SASL STATISTICS
OPTIONS_DEFAULT=	GSTREAMER LZ4 SASL

STATISTICS_DESC=	Statistic code

GSTREAMER_LIB_DEPENDS=		liborc-0.4.so:devel/orc
GSTREAMER_USES=			gstreamer
GSTREAMER_MESON_ON=	-Dgstreamer=1.0
GSTREAMER_MESON_OFF=	-Dgstreamer=no
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_MESON_TRUE=	lz4
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MESON_TRUE=	sasl
STATISTICS_MESON_ON=	-Dstatistics=true

.include <bsd.port.mk>
