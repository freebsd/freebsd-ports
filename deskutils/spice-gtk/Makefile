# Created by: olevole@olevole.ru
# $FreeBSD$

PORTNAME=	spice-gtk
PORTVERSION=	0.33
PORTREVISION?=	0
CATEGORIES?=	deskutils gnome
MASTER_SITES=	http://www.spice-space.org/download/gtk/

MAINTAINER=	olevole@olevole.ru
COMMENT?=	Gtk client and libraries for SPICE remote desktop servers

LICENSE=	GPLv2

USE_XORG=	pixman
USE_GNOME=	gnomeprefix gtk20 gtk30 intltool introspection:build
USES=		autoreconf cpe gmake jpeg libtool pkgconfig tar:bzip2 \
		python ssl localbase:ldflags
CPE_VENDOR=	redhat

BUILD_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${PY_FLAVOR}
RUN_DEPENDS=	spice-protocol>=0.12.10:devel/spice-protocol

.if defined(SPICE_SLAVE)
PORTREVISION=	1
CATEGORIES+=	python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
USES:=		${USES:Npython} python:2.7
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gtk2>=0:x11-toolkits/py-gtk2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gtk2>=0:x11-toolkits/py-gtk2
CONFIGURE_ARGS+=	--with-python
.endif

SPICE_SSL_CFLAGS=	-I${OPENSSLINC}
SPICE_SSL_LIBS=	-L${OPENSSLLIB} -lcrypto -lssl
CONFIGURE_ENV+=	SSL_CFLAGS="${SPICE_SSL_CFLAGS}" SSL_LIBS="${SPICE_SSL_LIBS}" \
		OPENSSL_CFLAGS="${SPICE_SSL_CFLAGS}" OPENSSL_LIBS="${SPICE_SSL_LIBS}"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# we can't use pathfix with USES=autoreconf
MAKE_ARGS=	pkgconfigdir="$(PREFIX)/libdata/pkgconfig"

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS DOCS SASL
OPTIONS_DEFAULT=	GSTREAMER SASL
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	GSTREAMER PULSEAUDIO NOAUDIO

NOAUDIO_DESC=		Disable audio backend

GSTREAMER_CONFIGURE_ON=	--with-audio=gstreamer
GSTREAMER_USE=	GSTREAMER1=yes
PULSEAUDIO_CONFIGURE_ON=	--with-audio=pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
NOAUDIO_CONFIGURE_ON=		--with-audio=no
SASL_CONFIGURE_WITH=		sasl=yes
SASL_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2

.include <bsd.port.mk>
