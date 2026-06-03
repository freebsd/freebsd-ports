PORTNAME=	Pympler
DISTVERSION=	1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pympler-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Measure, monitor and analyze the memory behavior of Python objects
WWW=		https://github.com/pympler/pympler

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
				${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
