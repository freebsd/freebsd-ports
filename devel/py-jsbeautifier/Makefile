PORTNAME=	jsbeautifier
PORTVERSION=	1.14.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	JavaScript unobfuscator and beautifier
WWW=		https://jsbeautifier.org/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}editorconfig>=0.12.0:editors/py-editorconfig@${PY_FLAVOR}

USES?=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
