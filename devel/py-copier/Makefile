PORTNAME=	copier
PORTVERSION=	6.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for rendering project templates

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.3:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dunamai>=1.7.0:devel/py-dunamai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iteration-utilities>=0.11.0:devel/py-iteration-utilities@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jinja2-ansible-filters>=1.3.1:devel/py-jinja2-ansible-filters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plumbum>=1.6.9:sysutils/py-plumbum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.9.0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7.1:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml-include>=1.2:devel/py-pyyaml-include@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}questionary>=1.8.1:devel/py-questionary@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.cached-property>=1.0.0:devel/py-backports.cached-property@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.4<5.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4<5.0.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
