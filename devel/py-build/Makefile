# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	build
PORTVERSION=	0.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEP517 package builder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=19.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pep517>=0.9.1:devel/py-pep517@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.0:textproc/py-toml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+= ${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0.22:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
