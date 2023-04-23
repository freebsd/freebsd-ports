PORTNAME=	beartype
DISTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast runtime type checking in pure Python
WWW=		https://github.com/beartype/beartype

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist pytest # tests fail, see https://github.com/beartype/beartype/issues/207

NO_ARCH=	yes

.include <bsd.port.mk>
