# $FreeBSD$

PORTNAME=	exaile
PORTVERSION=	4.0.${COMMITDATE}
CATEGORIES=	audio
PKGNAMESUFFIX=	-devel

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Full featured python-based music player for GTK+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bsddb3>0:databases/py-bsddb3@${PY_FLAVOR}

USE_GITHUB=	yes
GH_TAGNAME=	9f584a7
COMMITDATE=	20190301

NO_ARCH=	yes
USES=		desktop-file-utils gmake gnome python:2.7
USE_GNOME=	gtk30 librsvg2 pygobject3
USE_GSTREAMER1=	good faad
OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_BUILD_DEPENDS=	help2man:misc/help2man
NLS_INSTALL_TARGET_OFF=	install_no_locale
CDDB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cddb>0:audio/py-cddb@${PY_FLAVOR}
HAL_LIB_DEPENDS=	libhal.so:sysutils/hal

MAKE_ENV=	EPREFIX=${PREFIX} \
		PYTHON2_CMD=${PYTHON_CMD} \
		XDGCONFDIR=${PREFIX}/etc/xdg \
		MANPREFIX=${PREFIX}

.include <bsd.port.mk>
