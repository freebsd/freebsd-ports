PORTNAME=	etuples
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.9
#MASTER_SITES=	PYPI # no tests
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python S-expression emulation using tuple-like objects
WWW=		https://github.com/pythological/etuples

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cons>0:devel/py-cons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multipledispatch>0:devel/py-multipledispatch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail: TypeError: Tried to dispatch on non-type, see https://github.com/pythological/etuples/issues/24

USE_GITHUB=	yes
GH_ACCOUNT=	pythological
GH_PROJECT=	etuples

NO_ARCH=	yes

.include <bsd.port.mk>
