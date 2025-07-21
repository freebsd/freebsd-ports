PORTNAME=	ete3
DISTVERSION=	3.1.3
PORTREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for the analysis and visualization of trees
WWW=		http://etetoolkit.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python pyqt:5 shebangfix
USE_PYTHON=	distutils concurrent autoplist pytest # some tests fail, see https://github.com/etetoolkit/ete/issues/643
USE_PYQT=	pyqt5

SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
