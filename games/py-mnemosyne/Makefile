# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mnemosyne
PORTVERSION=		2.7.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	games education python
MASTER_SITES=	SF/mnemosyne-proj/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mnemosyne-${DISTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.4:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googletrans>=0:textproc/py-googletrans@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gtts>=0:audio/py-gtts@${PY_FLAVOR}

USES=		pyqt:5 python:3.7+ shebangfix dos2unix #due textproc/py-googletrans
USE_PYQT=	gui_run network_run printsupport_run sip_run sql_run webengine_run
USE_PYTHON=	autoplist concurrent distutils

DOS2UNIX_GLOB=	*.py
DOS2UNIX_FILES=	mnemosyne/pyqt_ui/mnemosyne
SHEBANG_GLOB=	*.py
SHEBANG_FILES=	mnemosyne/pyqt_ui/mnemosyne

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|icons|pixmaps|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
