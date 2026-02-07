PORTNAME=	flake8
PORTVERSION=	7.3.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Code checking using pep8 and pyflakes
WWW=		https://pypi.org/project/flake8/ \
		https://github.com/PyCQA/flake8

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mccabe>=0:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0:devel/py-pyflakes@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	PyCQA
USE_PYTHON=	autoplist concurrent distutils pytest
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -Ee '/(mccabe|pycodestyle|pyflakes)/s|>.*||' ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
