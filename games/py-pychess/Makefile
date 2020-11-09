# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pychess
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	https://github.com/pychess/pychess/releases/download/${PORTVERSION}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	GTK chess client written in Python

LICENSE=	GPLv3

COMMON_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy*>1.:databases/py-sqlalchemy13@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil*>0.:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject*>2:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets*>7.:devel/py-websockets@${PY_FLAVOR}
RUN_DEPENDS=	${COMMON_DEPENDS}
BUILD_DEPENDS=	${COMMON_DEPENDS}

USES=		desktop-file-utils display:configure gettext gnome python:3.3+
# DISPLAY must be set at all steps:
.for t in build install stage
_USES_$t+=	${_USES_configure}
.endfor
USE_GSTREAMER1=	yes
USE_PYTHON=	distutils autoplist
USE_GNOME=	gtksourceview3:run glib20 gtk30 librsvg2 introspection
INSTALLS_ICONS=	yes
PYDISTUTILS_INSTALLNOSINGLE=	nope

.include <bsd.port.mk>
