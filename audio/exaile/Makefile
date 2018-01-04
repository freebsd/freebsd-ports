# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exaile
PORTVERSION=	3.4.5
CATEGORIES=	audio
MASTER_SITES=	https://github.com/exaile/exaile/releases/download/${PORTVERSION}/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Full featured python-based music player for GTK+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.11:audio/py-mutagen@${PY_FLAVOR}

MAKE_ENV+=	PYTHON2_CMD=${PYTHON_CMD} XDGCONFDIR=${PREFIX}/etc/xdg
USES=		desktop-file-utils gmake python:2
USE_GNOME=	pygtk2 librsvg2
USE_GSTREAMER=	good faad python

OPTIONS_DEFINE=		BAD CDDB DBUS HAL NOTIFY NLS SEXY
OPTIONS_DEFAULT=	BAD CDDB DBUS HAL NOTIFY SEXY
OPTIONS_SUB=		yes
BAD_DESC=		Install bad GStreamer plugins
BAD_USE=		GSTREAMER=bad
CDDB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cddb>=1.4:audio/py-cddb@${PY_FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.1:devel/py-dbus@${PY_FLAVOR}
HAL_LIB_DEPENDS=	libhal.so:sysutils/hal
NOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:devel/py-notify@${PY_FLAVOR}
NLS_USES=		gettext
NLS_INSTALL_TARGET_OFF=	install_no_locale
SEXY_DESC=		UI enchancements
SEXY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sexy>=0.1.9:x11-toolkits/py-sexy@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
