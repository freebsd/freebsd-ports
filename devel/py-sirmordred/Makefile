PORTNAME=	sirmordred
DISTVERSION=	1.1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Drive GrimoireLab tools to produce a dashboard
WWW=		https://github.com/chaoss/grimoirelab-sirmordred

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}cereslib>=0.3:devel/py-cereslib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=6.4.1:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch6>=6.3.1:textproc/py-elasticsearch6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch-dsl6>=6.3.1:textproc/py-elasticsearch-dsl6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}file-read-backwards>=3.1.0:textproc/py-file-read-backwards@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graal>=0.3:devel/py-graal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoire-elk>=0.102:textproc/py-grimoire-elk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-panels>=0.1:textproc/py-grimoirelab-panels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=0.3:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kidash>=0.5:textproc/py-kidash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval>=0.19:devel/py-perceval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-mozilla>=0.3:devel/py-perceval-mozilla@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-opnfv>=0.2:devel/py-perceval-opnfv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-puppet>=0.2:devel/py-perceval-puppet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-weblate>=0.2:devel/py-perceval-weblate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortinghat>=0.7.20:devel/py-sortinghat@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
