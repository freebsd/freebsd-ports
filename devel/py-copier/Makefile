PORTNAME=	copier
PORTVERSION=	9.10.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for rendering project templates
WWW=		https://copier.readthedocs.io/en/latest/ \
		https://github.com/copier-org/copier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dunamai>=1.7.0:devel/py-dunamai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcy>=1.17:devel/py-funcy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.5:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jinja2-ansible-filters>=1.3.1:devel/py-jinja2-ansible-filters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.3.6:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plumbum>=1.6.9:sysutils/py-plumbum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.4.2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7.1:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}questionary>=1.8.1:devel/py-questionary@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}eval-type-backport>=0.1.3<0.3.0:devel/py-eval-type-backport@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0<5.0.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
