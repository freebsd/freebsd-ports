PORTNAME=	jupyter-server
PORTVERSION=	2.17.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyter-server/jupyter_server/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyter_server-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	The backend to Jupyter web applications
WWW=		https://jupyter-server.readthedocs.io/en/latest/ \
		https://github.com/jupyter-server/jupyter_server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.8.1:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.11:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.1.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argon2-cffi>=21.1:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=7.4.4:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=4.12:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-events>=0.11.0:devel/py-jupyter-events@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server-terminals>=0.4.4:devel/py-jupyter-server-terminals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=6.4.4:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=5.3.0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.9:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=24:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=1.8.2:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminado>=0.8.3:net/py-terminado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.2.0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.6.0:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=1.3:www/py-websocket-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}overrides>=5.0:devel/py-overrides@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
