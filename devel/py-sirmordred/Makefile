PORTNAME=	sirmordred
DISTVERSION=	1.1.6
PORTREVISION=	1
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
		${PYTHON_PKGNAMEPREFIX}cereslib>=1.0.9:devel/py-cereslib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=6.4.1:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch6>=6.3.1:textproc/py-elasticsearch6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch-dsl6>=6.3.1:textproc/py-elasticsearch-dsl6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}file-read-backwards>=3.1.0:textproc/py-file-read-backwards@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graal>=1.1.2:devel/py-graal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoire-elk>=1.3.4:textproc/py-grimoire-elk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-panels>=1.1.2:textproc/py-grimoirelab-panels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grimoirelab-toolkit>=1.0.9:devel/py-grimoirelab-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kidash>=1.0.10:textproc/py-kidash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval>=1.1.1:devel/py-perceval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-mozilla>=1.0.11:devel/py-perceval-mozilla@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-opnfv>=1.0.11:devel/py-perceval-opnfv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-puppet>=1.0.11:devel/py-perceval-puppet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}perceval-weblate>=1.0.11:devel/py-perceval-weblate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortinghat>=1.6.2:devel/py-sortinghat@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
