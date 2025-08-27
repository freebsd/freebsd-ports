PORTNAME=	commitizen
PORTVERSION=	3.31.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Commitizen client tool written in Python
WWW=		https://commitizen-tools.github.io/commitizen/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_BDEPS=	poetry-core>0:devel/py-poetry-core
PY_RDEPS=	Jinja2>=2.10.3:devel/py-Jinja2 \
		argcomplete>=1.12.1:devel/py-argcomplete \
		charset-normalizer>=2.1.0:textproc/py-charset-normalizer \
		colorama>=0.4.1:devel/py-colorama \
		decli>=0.6.0:devel/py-decli \
		packaging>=19:devel/py-packaging \
		pyyaml>=3.08:devel/py-pyyaml \
		prompt-toolkit>0:devel/py-prompt-toolkit \
		questionary>=2.0:devel/py-questionary \
		termcolor>=1.1:devel/py-termcolor \
		tomlkit>=0.5.3:textproc/py-tomlkit
BUILD_DEPENDS=	${PY_BDEPS:S,^,${PYTHON_PKGNAMEPREFIX},:S,$,@${PY_FLAVOR},}
RUN_DEPENDS=	${PY_RDEPS:S,^,${PYTHON_PKGNAMEPREFIX},:S,$,@${PY_FLAVOR},}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

.if ${PYTHON_MAJOR_VER} == 3 && ${PYTHON_VER:E} < 10
PY_RDEPS+=	importlib-metadata>=8.0.0:devel/py-importlib-metadata
.endif
