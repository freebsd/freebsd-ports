PORTNAME=	mnemosyne
PORTVERSION=	2.10.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games education python
MASTER_SITES=	SF/mnemosyne-proj/${PORTNAME}/${PORTNAME}-${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mnemosyne-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process
WWW=		https://www.mnemosyne-proj.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}argon2-cffi>0:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=5.0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googletrans>=3.0:textproc/py-googletrans@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gTTS>=0:audio/py-gtts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.4:www/py-webob@${PY_FLAVOR}

USES=		pyqt:6 python shebangfix
USE_PYQT=	pyqt6:run sip:run webengine:run
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	mnemosyne/pyqt_ui/mnemosyne

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|icons|pixmaps|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
