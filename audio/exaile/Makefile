PORTNAME=	exaile
DISTVERSION=	4.1.4
CATEGORIES=	audio

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Full featured python-based music player for GTK
WWW=		https://exaile.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}berkeleydb>0:databases/py-berkeleydb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR}

USES=		desktop-file-utils gmake gnome gstreamer python
USE_GITHUB=	yes
USE_GNOME=	gtk30 librsvg2 pygobject3
USE_GSTREAMER=	faad good

MAKE_ENV=	EPREFIX=${PREFIX} \
		PYTHON3_CMD=${PYTHON_CMD} \
		XDGCONFDIR=${PREFIX}/etc/xdg

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS NLS UDISKS2
OPTIONS_SUB=	yes

UDISKS2_DESC=	UDISKS2 implementation for hardware detection

NLS_BUILD_DEPENDS=	help2man:misc/help2man
NLS_USES=		gettext
NLS_INSTALL_TARGET_OFF=	install_no_locale
UDISKS2_RUN_DEPENDS=	${LOCALBASE}bin/bsdisks:sysutils/bsdisks

.include <bsd.port.mk>
