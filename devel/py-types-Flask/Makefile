PORTNAME=	types-Flask
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Typing stubs for Flask
WWW=		https://pypi.org/project/types-Flask/

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}types-Jinja2>=0:devel/py-types-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-Werkzeug>=0:devel/py-types-Werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-click>=0:devel/py-types-click@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
