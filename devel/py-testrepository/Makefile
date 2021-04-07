PORTNAME=	testrepository
DISTVERSION=	0.0.20
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Repository of test results

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=		${WRKSRC}/Apache-2.0
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fixtures>0:devel/py-fixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-subunit>=0.0.18:devel/py-python-subunit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=0.9.30:devel/py-testtools@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils concurrent autoplist
SHEBANG_FILES=	testr

NO_ARCH=	yes

.include <bsd.port.mk>
