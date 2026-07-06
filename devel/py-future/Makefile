PORTNAME=	future
DISTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Clean single-source support for Python 3 and 2
WWW=		https://python-future.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:2.7+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30000
DEPRECATED=		No longer needed post Python 2 EOL
EXPIRATION_DATE=	2026-09-30
.else
DEPRECATED=	Outlived it's purpose
EXPIRATION_DATE=	2026-12-31
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest tests

.include <bsd.port.post.mk>
