PORTNAME=	inline-snapshot
DISTVERSION=	0.18.1
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
		${PYTHON_PKGNAMEPREFIX}black>=23.3.0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.4:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}executing>=2.1.0:devel/py-executing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
