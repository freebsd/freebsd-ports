# Created by: Jonathan Anderson <jonathan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	git-cola
PORTVERSION=	2.6
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Sleek and powerful Git GUI

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:net/py-qt4-network@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui@${PY_FLAVOR} \

USE_GITHUB=	yes

USES=		desktop-file-utils gettext gmake python
INSTALLS_ICONS=	YES

MAKE_ARGS=	prefix=${PREFIX} PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
