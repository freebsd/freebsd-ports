# Created by: olevole@olevole.ru
# $FreeBSD$

PORTNAME=	spice-gtk
PORTVERSION=	0.26
CATEGORIES?=	deskutils gnome
MASTER_SITES=	http://www.spice-space.org/download/gtk/

MAINTAINER=	olevole@olevole.ru
COMMENT?=	Gtk client and libraries for SPICE remote desktop servers

LICENSE=	GPLv2

USE_XORG=	pixman
USE_GNOME=	gnomeprefix gtk20 gtk30 intltool introspection:build
USES=		cpe gmake jpeg libtool pkgconfig tar:bzip2 pathfix
CPE_VENDOR=	redhat

.if defined(SPICE_SLAVE)
CATEGORIES+=	python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk2>=0:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk2>=0:${PORTSDIR}/x11-toolkits/py-gtk2
CONFIGURE_ARGS+=	--with-python
PLIST_FILES+=	%%PYTHON_SITELIBDIR%%/SpiceClientGtk.a \
		%%PYTHON_SITELIBDIR%%/SpiceClientGtk.so
USES+=	python
.endif

CONFIGURE_ENV+=	SSL_CFLAGS=-I${OPENSSLINC} \
		SSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
GSTREAMER_USE=	gstreamer=yes
PULSEAUDIO_CONFIGURE_ON=	--with-audio=pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
NOAUDIO_CONFIGURE_ON=		--with-audio=no
SASL_CONFIGURE_WITH=		sasl=yes
SASL_LIB_DEPENDS=		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

.include <bsd.port.mk>
