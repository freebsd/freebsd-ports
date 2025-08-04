PORTNAME=	inline-snapshot
DISTVERSION=	0.20.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	inline_snapshot-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Create and update inline snapshots in your Python code
WWW=		https://github.com/15r10nk/inline-snapshot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asttokens>=2.0.5:devel/py-asttokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}executing>=2.2.0:devel/py-executing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=		BLACK DIRTY-EQUALS
OPTIONS_DEFAULT=	BLACK DIRTY-EQUALS

BLACK_DESC=		Format generated code with Black
DIRTY-EQUALS_DESC=	Support for normalization of data that changes frequently

BLACK_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}black>=23.3.0:devel/py-black@${PY_FLAVOR}
DIRTY-EQUALS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.9.0:devel/py-dirty-equals@${PY_FLAVOR}

.include <bsd.port.mk>
