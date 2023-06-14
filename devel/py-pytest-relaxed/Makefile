PORTNAME=	pytest-relaxed
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Relaxed test discovery/organization for pytest
WWW=		https://pytest-relaxed.readthedocs.io/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest4>=3:devel/py-pytest4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=4:devel/py-decorator@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
