PORTNAME=	orca
PORTVERSION=	47.5
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scriptable screen reader
WWW=		https://gitlab.gnome.org/GNOME/orca

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atspi>0:accessibility/py-atspi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}speech-dispatcher>0:accessibility/py-speech-dispatcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		itstool:textproc/itstool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}speech-dispatcher>0:accessibility/py-speech-dispatcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atspi>0:accessibility/py-atspi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}orca
PORTSCOUT=	limit:^47\.

NO_ARCH=	yes
USES=		cpe gettext gnome localbase meson pkgconfig python \
		tar:xz
USE_GNOME=	atk gtk30 libwnck3 pygobject3
CPE_VENDOR=	gnome

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	SPIEL

SPIEL_DESC=	Speech synthesis providers support
SPIEL_LIB_DEPENDS=	libspiel-1.0.so:accessibility/libspiel
SPIEL_MESON_TRUE=	spiel

.include <bsd.port.mk>
