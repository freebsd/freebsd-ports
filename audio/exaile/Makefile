PORTNAME=	exaile
DISTVERSION=	4.1.1
CATEGORIES=	audio

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Full featured python-based music player for GTK+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bsddb3>0:databases/py-bsddb3@${PY_FLAVOR}

USE_GITHUB=	yes

NO_ARCH=	yes
USES=		desktop-file-utils gmake gnome python:3.6+
USE_GNOME=	gtk30 librsvg2 pygobject3
USE_GSTREAMER1=	good faad
OPTIONS_DEFINE=	DOCS NLS UDISKS2
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_BUILD_DEPENDS=	help2man:misc/help2man
NLS_INSTALL_TARGET_OFF=	install_no_locale
UDISKS2_DESC=	UDISKS2 implementation for hardware detection
UDISKS2_RUN_DEPENDS=	${LOCALBASE}bin/bsdisks:sysutils/bsdisks

MAKE_ENV=	EPREFIX=${PREFIX} \
		PYTHON3_CMD=${PYTHON_CMD} \
		XDGCONFDIR=${PREFIX}/etc/xdg \
		MANPREFIX=${PREFIX}

.include <bsd.port.mk>
