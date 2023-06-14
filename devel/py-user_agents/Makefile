PORTNAME=	user_agents
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_/-/}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python library to identify devices using User-Agent string
WWW=		https://github.com/selwin/python-user-agents

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ua_parser/__init__.py:devel/py-ua_parser@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
