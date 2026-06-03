PORTNAME=	mnemosyne-proj
DISTVERSION=	2.11
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games education python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mnemosyne_proj-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process
WWW=		https://www.mnemosyne-proj.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		gmake>0:devel/gmake
RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}argon2-cffi>0:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=5.0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gTTS>=0:audio/py-gtts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.4:www/py-webob@${PY_FLAVOR}

USES=		pyqt:6 python qt:6 shebangfix
USE_PYQT=	pyqt6:run webengine:run
USE_PYTHON=	autoplist concurrent pep517
USE_QT=		sqldriver-sqlite:run

SHEBANG_FILES=	mnemosyne/pyqt_ui/mnemosyne

BINARY_ALIAS=	make=gmake

NO_ARCH=	yes

.include <bsd.port.mk>
