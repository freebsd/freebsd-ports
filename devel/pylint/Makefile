PORTNAME=	pylint
PORTVERSION=	2.15.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality
WWW=		https://www.pylint.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=2.12.4<2.14.0_99:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.2:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=4.2.5<6:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0.6<0.8:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.2.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.10.1:textproc/py-tomlkit@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
