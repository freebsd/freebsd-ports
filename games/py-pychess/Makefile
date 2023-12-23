PORTNAME=	pychess
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	https://github.com/pychess/pychess/releases/download/${PORTVERSION}/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	GTK chess client written in Python
WWW=		https://github.com/pychess/pychess

LICENSE=	GPLv3

COMMON_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0.:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>2:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>11.:devel/py-websockets@${PY_FLAVOR}
RUN_DEPENDS=	${COMMON_DEPENDS}
BUILD_DEPENDS=	${COMMON_DEPENDS}

USES=		desktop-file-utils display:configure gettext gnome gstreamer python
# DISPLAY must be set at all steps:
.for t in build install stage
_USES_$t+=	${_USES_configure}
.endfor
USE_PYTHON=	distutils autoplist
USE_GNOME=	gtksourceview3:run glib20 gtk30 librsvg2 introspection
PYDISTUTILS_INSTALLNOSINGLE=	nope

NO_ARCH=	yes

.include <bsd.port.mk>
