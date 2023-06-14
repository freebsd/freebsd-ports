PORTNAME=	jplephem
PORTVERSION=	2.18
PORTREVISION=	1
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python version of NASA DE4xx ephemerides
WWW=		https://github.com/brandon-rhodes/python-jplephem

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	bash:shells/bash	\
		${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	brandon-rhodes
GH_PROJECT=	python-jplephem

USES=		python shebangfix
USE_PYTHON=	distutils
SHEBANG_FILES=	test.sh	bin/doctest.sh bin/parse_zzidmap.sh bin/benchmark.py
NO_ARCH=	yes

do-test:	install
	(cd ${WRKSRC} && ${SETENV} PYTHON=${PYTHON_CMD} ./test.sh)

.include <bsd.port.mk>
