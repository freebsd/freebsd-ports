PORTNAME=	pony
DISTVERSION=	0.7.20
CATEGORIES=	databases devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@sys.it.com
COMMENT=	Pony ORM is easy to use and powerful object-relational mapper
WWW=		https://ponyorm.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

TEST_ENV=	PYTHONPATH=${WRKSRC}

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest discover \
		-s pony/orm/tests -p 'test*.py'

.include <bsd.port.mk>
