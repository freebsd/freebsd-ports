PORTNAME=	pycdlib
PORTVERSION=	1.16.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	des@FreeBSD.org
COMMENT=	Pure python library to parse, write, and create ISO9660 files
WWW=		http://github.com/clalancette/pycdlib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.mk>
