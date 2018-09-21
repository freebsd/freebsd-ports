# $FreeBSD$

PORTNAME=	tree-format
PORTVERSION=	0.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Generate nicely formatted trees

LICENSE=	APACHE20

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}testtools>0:devel/py-testtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/tox-${PYTHON_VER} -e py${PYTHON_SUFFIX}

.include <bsd.port.mk>
