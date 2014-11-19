# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exaile
PORTVERSION=	3.4.0.2
CATEGORIES=	audio
MASTER_SITES=	https://codeload.github.com/exaile-dev/exaile/tar.gz/
DISTNAME=	${PORTVERSION}
EXTRACT_SUFX=
DIST_SUBDIR=	exaile

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full featured python-based music player for GTK+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.11:${PORTSDIR}/audio/py-mutagen

MAKE_ENV+=	PYTHON2_CMD=${PYTHON_CMD} XDGCONFDIR=${PREFIX}/etc/xdg
USES=		desktop-file-utils gmake python:2
USE_GNOME=	pygtk2 librsvg2
USE_GSTREAMER=	good faad python
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		BAD CDDB DBUS HAL NOTIFY NLS SEXY
OPTIONS_DEFAULT=	BAD CDDB DBUS HAL NOTIFY NLS SEXY
OPTIONS_SUB=		yes
BAD_DESC=		Install bad GStreamer plugins
BAD_USE=		GSTREAMER=bad
CDDB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cddb>=1.4:${PORTSDIR}/audio/py-cddb
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.82.1:${PORTSDIR}/devel/py-dbus
HAL_LIB_DEPENDS=	libhal.so:${PORTSDIR}/sysutils/hal
NOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:${PORTSDIR}/devel/py-notify
NLS_USES=		gettext
NLS_INSTALL_TARGET_OFF=	install_no_locale
SEXY_DESC=		UI enchancements
SEXY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sexy>=0.1.9:${PORTSDIR}/x11-toolkits/py-sexy

# Disable manpage building for now - it's too expensive
post-patch:
	@${REINPLACE_CMD} -e 's|compile locale manpage|compile locale|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
