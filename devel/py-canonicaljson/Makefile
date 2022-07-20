PORTNAME=	canonicaljson
PORTVERSION=	1.6.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Canonical JSON

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=3.14.0:devel/py-simplejson@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}frozendict>=1.0:devel/py-frozendict@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	FROZENDICT
FROZENDICT_DESC=Frozendict immutable dictionaries support

FROZENDICT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}frozendict>=1.0:devel/py-frozendict@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
