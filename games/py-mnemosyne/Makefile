# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mnemosyne
PORTVERSION=	2.6.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games python
MASTER_SITES=	SF/mnemosyne-proj/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mnemosyne-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.4:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=0:www/py-cheroot@${PY_FLAVOR}

USES=		pyqt:5 python:3.5+
USE_PYQT=	gui_run network_run printsupport_run sip_run sql_run webengine_run
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\(share/\)icons|\1pixmaps|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
