# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	visvis
PORTVERSION=	1.13.0
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Object oriented approach to visualization of 1D to 4D data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}imageio>=0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside2>=0:devel/pyside2@${PY_FLAVOR}

USES=		gl python:3.5+ pyqt:5
USE_GL=		gl
USE_PYQT=	core gui
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+

NO_ARCH=	yes

.include <bsd.port.mk>
