PORTNAME=	construct-classes
PORTVERSION=	0.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Parse your binary structs into dataclasses
WWW=		https://pypi.org/project/construct-classes/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}construct>=2.10:devel/py-construct@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
