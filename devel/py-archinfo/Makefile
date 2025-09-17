PORTNAME=	archinfo
DISTVERSIONPREFIX=	v
DISTVERSION=	9.2.175
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	schaiba@gmail.com
COMMENT=	Classes with architecture-specific information useful to other projects
WWW=		https://github.com/angr/archinfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyvex>0:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicorn>0:emulators/py-unicorn@${PY_FLAVOR}

USES=		angr:nose python
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist distutils

TESTING_UNSAFE=	nose does not yet support Python 3.11 so 'make test' will fail

NO_ARCH=	yes

post-extract:
	${SED} 's|%%DISTVERSION%%|${DISTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
