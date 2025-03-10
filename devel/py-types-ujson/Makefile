PORTNAME=	types-ujson
DISTVERSION=	5.10.0.20240515
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Typing stubs for ujson
WWW=		https://github.com/python/typeshed

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	distutils
NO_ARCH=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/ujson-stubs/METADATA.toml	\
		%%PYTHON_SITELIBDIR%%/ujson-stubs/__init__.pyi	\
		%%PYTHON_SITELIBDIR%%/ujson-stubs/py.typed

.include <bsd.port.mk>
