PORTNAME=	commitizen
PORTVERSION=	3.31.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Commitizen client tool written in Python
WWW=		https://commitizen-tools.github.io/commitizen/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.12.1:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2.1.0<4:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.1<0.5:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decli>=0.6.0<0.7:devel/py-decli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=8.0.0<9:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=19:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.08:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}questionary>=2.0<3:devel/py-questionary@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.5.3<1.0.0:textproc/py-tomlkit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	importlib-metadata>=8.0.0<9:devel/py-importlib-metadata
.endif

.include <bsd.port.post.mk>
