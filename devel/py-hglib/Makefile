PORTNAME=	hglib
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Library with a fast, convenient interface to Mercurial
WWW=		https://www.mercurial-scm.org/wiki/PythonHglib

LICENSE=	MIT

RUN_DEPENDS+=	${PY_MERCURIAL}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
