PORTNAME=	aiofile
PORTVERSION=	3.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous file operations
WWW=		https://github.com/mosquito/aiofile

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENCE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}caio>=0.9.0:devel/py-caio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
