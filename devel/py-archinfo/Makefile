# $FreeBSD$

PORTNAME=	archinfo
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Classes with architecture-specific information useful to other projects

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>0:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicorn>0:emulators/py-unicorn@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} tests/*)

.include "${.CURDIR}/../../security/py-angr/Makefile.version"
.include <bsd.port.mk>
