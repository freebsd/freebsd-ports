PORTNAME=	aiologic
DISTVERSION=	0.17.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GIL-powered locking library for Python
WWW=		https://github.com/x42005e1f/aiologic \
		https://aiologic.readthedocs.io/latest/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSES/ISC.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sniffio>=1.3.0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.16.0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		--thread-safety

# tests as of 0.17.1: 123 passed, 2 warnings in 120.47s (0:02:00)

.include <bsd.port.mk>
