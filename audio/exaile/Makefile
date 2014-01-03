# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exaile
PORTVERSION=	3.3.2
CATEGORIES=	audio
MASTER_SITES=	https://launchpadlibrarian.net/155081992/ \
		http://wickedmachine.net/mirror/

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Full featured python-based music player for GTK+

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.11:${PORTSDIR}/audio/py-mutagen

MAKE_ENV+=	PYTHON2_CMD=${PYTHON_CMD} XDGCONFDIR=${PREFIX}/etc/xdg
USE_GNOME=	pygtk2 librsvg2
USE_GSTREAMER=	python good faad
USE_PYTHON=	2

# The reality with these options is that they all will be autodetected and used
# if already installed. These just force Exaile to bring them in as well.
OPTIONS_DEFINE=	BAD CDDB DBUS HAL NOTIFY NLS SEXY
OPTIONS_DEFAULT=BAD CDDB DBUS HAL NOTIFY NLS SEXY
BAD_DESC=	Install bad GStreamer plugins
SEXY_DESC=	UI enhancements

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBAD}
USE_GSTREAMER+=	bad
.endif

.if ${PORT_OPTIONS:MCDDB}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cddb>=1.4:${PORTSDIR}/audio/py-cddb
.endif

.if ${PORT_OPTIONS:MDBUS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.1:${PORTSDIR}/devel/py-dbus
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	libhal.so:${PORTSDIR}/sysutils/hal
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:${PORTSDIR}/devel/py-notify
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
INSTALL_TARGET=	install_no_locale
.endif

.if ${PORT_OPTIONS:MSEXY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sexy>=0.1.9:${PORTSDIR}/x11-toolkits/py-sexy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share\/man|man|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
