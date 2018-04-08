# $FreeBSD$

BROKEN=		Requires PyQt5 for python3 which is broken at the moment.

PORTNAME=	kajongg
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR}

USES=		cmake:outsource pkgconfig python:3 pyqt:5 kde:5 tar:xz \
		sqlite
USE_KDE=	config doctools ecm
USE_PYQT=	core gui svg widgets
USE_QT5=	core gui svg widgets \
		buildtools_build qmake_build

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
