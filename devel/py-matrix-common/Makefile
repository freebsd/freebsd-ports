PORTNAME=	matrix-common
DISTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	matrix_common-${PORTVERSION}

MAINTAINER=	ports@skyforge.at
COMMENT=	Common utilities for Synapse, Sydent and Sygnal

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>19.2.0:devel/py-attrs@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=18.9.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=2.3.1:devel/py-tox@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

# Dependency required by Python < 3.8
.if (${PYTHON_REL} < 30800)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=1.4:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

do-test:
	cd ${WRKSRC} && PYTHONPATH="." trial-${PYTHON_VER} tests

.include <bsd.port.post.mk>
