PORTNAME=	colored-traceback
PORTVERSION=	0.4.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Automatically color Python's uncaught exception tracebacks
WWW=		https://pypi.org/project/colored-traceback/

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
